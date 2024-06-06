#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include"solve.h" 


/*
����ԭ��: Element* find_element(Maze *maze, Position position);
��������: ���Թ��в��Ҹ���λ�õ�Ԫ�ء�
��������: Maze *maze���Թ��ṹ��ָ�롣 Position position�������ҵ�λ�á�
����ֵ����������λ�ڸ���λ�õ�Ԫ�ص�ָ�롣�����λ��û��Ԫ�أ��򷵻� NULL��
*/

/*
����ԭ��: void move_player(Maze *maze, int dx, int dy);
��������: �ƶ���ҵ������ķ�������µ�λ��û�з�����ײ����ô��ҵ�λ�ý������£�������Ƿ�ȡ��ʤ����
��������: Maze *maze���Թ��ṹ��ָ�롣 int dx, dy����ҵ��ƶ�����
����ֵ�������޷���ֵ��
*/

/*
����ԭ��: bool check_collision(Maze *maze, Position newPosition);
��������: �����ҵ���λ���Ƿ����ײ�����ȼ���Թ�Ԫ�أ�Ȼ������
��������: Maze *maze���Թ��ṹ��ָ�롣 Position newPosition����ҵ���λ�á�
����ֵ����������µ�λ������ײ������ true�����򷵻� false��������������Ҳ���� true��
*/

/*
����ԭ��: bool check_victory(Maze *maze);
��������: �������Ƿ񵽴��Թ��ĳ��ڣ����Ƿ���ʤ����
��������: Maze *maze���Թ��ṹ��ָ�롣
����ֵ�����������ҵ����Թ��ĳ��ڣ����� true�����򷵻� false��
*/


/* �����Թ�Ԫ�صĺ���ԭ�� */
Element* find_element(Maze *maze, Position position) {
    int i, j;
    for (i = 0; i < maze->height; ++i) {
        for (j = 0; j < maze->width; ++j) {
            if (maze->elements[j][i].position.x == position.x && maze->elements[j][i].position.y == position.y) {
                return &maze->elements[j][i];
            }
        }
    }
    return NULL;
}

/*����ƶ�����*/
void move_player(Maze *maze, int dx, int dy) {
    Position newPosition = {maze->player.position.x + dx, maze->player.position.y + dy};
    if (!check_collision(maze, newPosition)) {
        maze->player.position = newPosition;
        check_victory(maze);
    }
}


void move_player2(Maze *maze, int dx, int dy) {//����npc�����ƶ� 
    Position newPosition = {maze->player.position.x + dx, maze->player.position.y + dy};
    if (newPosition.x>=3&&newPosition.x<=11&&newPosition.y<=12&&newPosition.y>=2) {
        maze->player.position = newPosition;
    }
}

/*��ײ��⺯��*/
bool check_collision(Maze *maze, Position newPosition) {
    // Check maze elements
    Element* element = find_element(maze, newPosition);
    if (element) {
        if (element->type == 'w') {
            return true;
        } else if (element->type == 'K') {
            maze->player.keys++;
            element->type = ' ';
        } else if (element->type == 'T') {
            maze->player.life++;
            element->type = ' ';
        } else if (element->type == 'C') {
            maze->player.wealth++;
            element->type = ' ';
        } else if (element->type == 'D' && maze->player.keys > 0) {
            maze->player.keys--;
            element->type = 'O';
        } else if(element->type == 'D' && maze->player.keys <= 0) {
            return true;
        }
    }
    
    // Check monsters
    int i;
    for (i = 0; i < maze->num_monsters; ++i) {  
        if (maze->monsters[i].position.x == newPosition.x && maze->monsters[i].position.y == newPosition.y) {
            maze->player.life--;
            return maze->player.life <= 0 ? true : false;  // Prevent a dead player from moving
        }
    }
    
    return false;
}

/*ʤ����⺯��*/
bool check_victory(Maze *maze) {
    Element* element = find_element(maze, maze->player.position);
    return element && element->type == 'E';
}



//�������ģ��

typedef struct {
    Position pos;
    int distance;
    int keys; // number of keys
} QueueNode;

typedef struct {
    QueueNode *nodes;
    int front;
    int rear;
    int capacity;
} Queue;

/*����ԭ��: bool isempty(Queue *queue)
�������������һ�������Ƿ�Ϊ��
��������: ���е�ָ�� (Queue *queue)
����ֵ�������������Ϊ�շ���true�����򷵻�false (bool)
*/
bool isempty(Queue *queue) {
    return queue->front > queue->rear;
}

/*����ԭ��: QueueNode dequeue(Queue *queue)
�����������Ӷ�����ɾ��һ��Ԫ�ز�����
��������: ���е�ָ�� (Queue *queue)
����ֵ���������شӶ�����ɾ����Ԫ�� (QueueNode)
*/
QueueNode dequeue(Queue *queue) {
    if (isempty(queue)) {
        exit(EXIT_FAILURE);
    }
    QueueNode node = queue->nodes[queue->front];
    queue->front++;
    return node;
}

/*����ԭ��: void free_queue(Queue *queue)
�����������ͷŶ�����ռ���ڴ�
��������: ���е�ָ�� (Queue *queue)
����ֵ��������
*/
void free_queue(Queue *queue) {
    free(queue->nodes);
    free(queue);
}

/*����ԭ��: void free_distance_matrix(int **matrix, int height)
�����������ͷž��������ռ���ڴ�
��������: ��������ָ�� (int **matrix), �Թ��ĸ߶� (int height)
����ֵ��������
*/
void free_distance_matrix(int **matrix, int height) {
	int i;
    for ( i = 0; i < height; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}




/*����ԭ��: Queue *create_queue(int capacity)
�����������������и��������Ķ���
��������: ���е����� (int capacity)
����ֵ���������ش����Ķ��е�ָ�� (Queue *)
*/
Queue *create_queue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL) {
        exit(EXIT_FAILURE);
    }
    queue->nodes = (QueueNode *)malloc(capacity * sizeof(QueueNode));
    if (queue->nodes == NULL) {
        exit(EXIT_FAILURE);
    }
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

/*����ԭ��: void enqueue(Queue *queue, Position pos, int distance, int keys)
�������������½ڵ���ӵ�������
��������: ���е�ָ�� (Queue *queue), �ڵ��λ��(Position pos), ����ڵ����С����(int distance), ���е�Կ������ (int keys)
����ֵ��������
*/
void enqueue(Queue *queue, Position pos, int distance, int keys) {
    if (queue->rear >= queue->capacity - 1) {
        return;
    }
    queue->rear++;
    queue->nodes[queue->rear].pos = pos;
    queue->nodes[queue->rear].distance = distance;
    queue->nodes[queue->rear].keys = keys; // enqueue keys
}

/*����ԭ��: int **create_distance_matrix(int height, int width)
���������������������
��������: �Թ��ĸ߶� (int height), �Թ��Ŀ�� (int width)
����ֵ���������ش����ľ�������ָ�� (int **)
*/
int **create_distance_matrix(int height, int width) {
    int **matrix = (int **)malloc(height * sizeof(int *));
    if (matrix == NULL) {
        exit(EXIT_FAILURE);
    }
    int i,j; 
    for ( i = 0; i < height; ++i) {
        matrix[i] = (int *)malloc(width * sizeof(int));
        if (matrix[i] == NULL) {
            exit(EXIT_FAILURE);
        }
        for ( j = 0; j < width; ++j) {
            matrix[i][j] = INT_MAX;
        }
    }
    return matrix;
}

/*����ԭ��: bool is_valid_move(Maze *maze, Position pos, int keys)
��������������Ƿ�����ƶ�����λ��
��������: �Թ���ָ�� (Maze *maze), ��λ��(Position pos), ���е�Կ������ (int keys)
����ֵ��������������ƶ�����λ�ã�����true�����򷵻�false (bool)
*/
bool is_valid_move(Maze *maze, Position pos, int keys) {
    if (pos.x < 0 || pos.x >= maze->width || pos.y < 0 || pos.y >= maze->height) {
        return false;
    }
    Element *element = find_element(maze, pos);
    if (element == NULL) {
        return false;
    }
    if (element->type == 'D') { // ���������
        return keys > 0; // �����Կ�ף����Թ�ȥ
    }
    return element->type != 'w'; // �������ǽ�����Թ�ȥ
}

/*����ԭ��: Solution *find_shortest_path(Maze *maze)
�������������Թ���Ѱ�Ҵ���ʼλ�õ��յ�����·��
��������: �Թ���ָ�� (Maze *maze)
����ֵ���������ؽ��������ָ�룬�������·���ĳ��Ⱥ;���·�� (Solution *)
*/
Solution *find_shortest_path(Maze *maze) {
    Position start = maze->player.position;
    int start_keys = maze->player.keys;
    Position end = {0, 0};

    int i;
    for (i = 0; i < maze->height; ++i) {
        int j;
        for (j = 0; j < maze->width; ++j) {
            if (maze->elements[j][i].type == 'E') {
                end = maze->elements[j][i].position;
                break;
            }
        }
    }

    int **distance_matrix = create_distance_matrix(maze->height, maze->width);
    distance_matrix[start.y][start.x] = 0;

    Queue *queue = create_queue(maze->width * maze->height);
    enqueue(queue, start, 0, start_keys);

    int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!isempty(queue)) {
        QueueNode current = dequeue(queue);
        Position current_pos = current.pos;
        int current_distance = current.distance;
        int current_keys = current.keys;

        if (current_pos.x == end.x && current_pos.y == end.y) {
            break;
        }

        int i;
        for (i = 0; i < 4; ++i) {
            Position new_pos = {current_pos.x + moves[i][0], current_pos.y + moves[i][1]};
            int new_keys = current_keys;
            
            // �����λ���Ƿ���Կ�׻���
            int k; 
            for ( k = 0; k < maze->height; ++k) {
            	int l;
                for ( l = 0; l < maze->width; ++l) {
                    if (maze->elements[l][k].position.x == new_pos.x && maze->elements[l][k].position.y ==
new_pos.y) {
                        if (maze->elements[l][k].type == 'K') {
                            new_keys++; //Կ����������
                        } else if (maze->elements[l][k].type == 'D' && new_keys > 0) {
                            new_keys--; // Կ����������
                        }
                    }
                }
            }
            
            if (is_valid_move(maze, new_pos, new_keys) && current_distance + 1 < distance_matrix[new_pos.y][new_pos.x]) {
                distance_matrix[new_pos.y][new_pos.x] = current_distance + 1;
                enqueue(queue, new_pos, current_distance + 1, new_keys);  
            }
        }
    }

    Solution *solution = NULL;
    if (distance_matrix[end.y][end.x] != INT_MAX) {
        solution = (Solution *)malloc(sizeof(Solution));
        solution->length = distance_matrix[end.y][end.x];
        solution->path = (Position *)malloc(solution->length * sizeof(Position));
        Position current = end;
        int i;
        for (i = solution->length - 1; i >= 0; --i) {
            solution->path[i] = current;
            int j;
            for (j = 0; j < 4; ++j) {
                Position new_pos = {current.x + moves[j][0], current.y + moves[j][1]};
                if (is_valid_move(maze, new_pos, solution->length - i) && distance_matrix[new_pos.y][new_pos.x] == i) {
                    current = new_pos;
                    break;
                }
            }
        }
    }

    free_queue(queue);
    free_distance_matrix(distance_matrix, maze->height);

    return solution;
}


//������н�


void dfs(Maze *maze, Position current, Position end, Position *path, int path_length, Position **all_paths, int *num_paths, int keys, bool **visited) {
    if (current.x == end.x && current.y == end.y) {
        // Find a solution
        all_paths[*num_paths] = (Position *)malloc(path_length * sizeof(Position));
        memcpy(all_paths[*num_paths], path, path_length * sizeof(Position));
        (*num_paths)++;
    } else {
        int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int i; 
        for ( i = 0; i < 4; ++i) {
            Position new_pos = {current.x + moves[i][0], current.y + moves[i][1]};
            if (is_valid_move(maze, new_pos, keys) && !visited[new_pos.y][new_pos.x]) {
                visited[new_pos.y][new_pos.x] = true;  // Mark the position as visited
                int new_keys = keys;
                // Check if new position has a key
                int k; 
                for ( k = 0; k < maze->height; ++k) {
                	int l;
                    for ( l = 0; l < maze->width; ++l) {
                        if (maze->elements[l][k].position.x == new_pos.x && maze->elements[l][k].position.y == new_pos.y && maze->elements[l][k].type == 'K') {
                            new_keys++;  // Increase keys if there is a key
                        }
                    }
                }
                path[path_length] = new_pos;
                dfs(maze, new_pos, end, path, path_length + 1, all_paths, num_paths, new_keys, visited);
                visited[new_pos.y][new_pos.x] = false;  // Unmark the position when we leave it
            }
        }
    }
}

Position **find_all_paths(Maze *maze, int *num_paths) {
    Position start = maze->player.position;
    Position end = {0, 0};
    
    // find the end position same as before...
    
    Position *path = (Position *)malloc(maze->width * maze->height * sizeof(Position));  // Dynamically allocate memory for the path array
    Position **all_paths = (Position **)malloc(maze->width * maze->height * sizeof(Position *));
    bool **visited = (bool **)malloc(maze->height * sizeof(bool *));
    int i;
	for ( i = 0; i < maze->height; ++i) {
        visited[i] = (bool *)malloc(maze->width * sizeof(bool));
        memset(visited[i], 0, maze->width * sizeof(bool));  // Set all elements to false
    }
    
    *num_paths = 0;
    dfs(maze, start, end, path, 0, all_paths, num_paths, maze->player.keys, visited);
    
    for (i = 0; i < maze->height; ++i) {
        free(visited[i]);
    }
    free(visited);
    
    return all_paths;
}
 

//��ʾ����ģ��
/*����ԭ��: Position *next_step_hint(Maze *maze)
���������������Թ�����һ����ʾ
��������: �Թ���ָ�� (Maze *maze)
����ֵ��������һ����λ��ָ�롣����Ҳ����������������NULL (Position *)
*/
Position *next_step_hint(Maze *maze) {
    Solution *shortest_path = find_shortest_path(maze);
    if (!shortest_path) return NULL;
    
    Position *next_step = malloc(sizeof(Position));
    if (next_step) *next_step = shortest_path->path[0];

    free(shortest_path->path);
    free(shortest_path);

    return next_step;
}


void dfsmaze(Maze *maze, SolutionList *solution_list, Position pos, Position *path, int path_len) {
    if (pos.x < 0 || pos.x >= maze->width || pos.y < 0 || pos.y >= maze->height) {
        return;
    }
    if (maze->elements[pos.y][pos.x].type == 'w') {
        return;
    }
    if (maze->elements[pos.y][pos.x].type == 'E') {
        Solution solution;
        solution.path = malloc(sizeof(Position) * path_len);
        memcpy(solution.path, path, sizeof(Position) * path_len);
        solution.length = path_len;
        SolutionNode *node = malloc(sizeof(SolutionNode));
        node->solution = solution;
        node->next = solution_list->head;
        solution_list->head = node;
        solution_list->count++;
        return;
    }
    int i;
    for ( i = 0; i < maze->num_monsters; i++) {
        if (maze->monsters[i].position.x == pos.x && maze->monsters[i].position.y == pos.y) {
            return;
        }
    }
    for ( i = 0; i < path_len; i++) {
        if (path[i].x == pos.x && path[i].y == pos.y) {
            return;
        }
    }
    path[path_len] = pos;
    dfsmaze(maze, solution_list, (Position){pos.x + 1, pos.y}, path, path_len + 1);
    dfsmaze(maze, solution_list, (Position){pos.x - 1, pos.y}, path, path_len + 1);
    dfsmaze(maze, solution_list, (Position){pos.x, pos.y + 1}, path, path_len + 1);
    dfsmaze(maze, solution_list, (Position){pos.x, pos.y - 1}, path, path_len + 1);
}

void solve_maze(Maze *maze, SolutionList *solution_list) {
    Position *path = malloc(sizeof(Position) * maze->width * maze->height);
    dfsmaze(maze, solution_list, maze->player.position, path, 0);
}



/*������н⺯��*/ 
void print_solutions(SolutionList *solution_list) {
    printf("Total number of solutions: %d\n", solution_list->count);
    SolutionNode *node = solution_list->head;
    while (node != NULL) {
        printf("Solution length: %d\n", node->solution.length);
        int i;
        int j; 
        for ( i = 0; i < node->solution.length; i++) {
            printf("(%d,%d)", node->solution.path[i].x,node->solution.path[i].y);
            if(i!=node->solution.length-1){
                printf(" -> ");
            }
        }
        printf("\n");
        node = node->next;
    }
}
//�ͷŴ������н������ṹ 
void free_solution_list(SolutionList *solution_list) {
    SolutionNode *current_node = solution_list->head;
    while (current_node != NULL) {
        SolutionNode *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    solution_list->head = NULL;
    solution_list->count = 0;
}
//�ͷŴ��浥����ĺ��� 
void freeSolution(Solution *solution) {
    if (solution->path) {
        free(solution->path);
    }
}
//�ͷŵ�ͼ 
void freeMaze(Maze *maze) {
	int i;
    for ( i = 0; i < maze->height; i++) {
        free(maze->elements[i]);
    }
    free(maze->elements);
}







