#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"file.h" 
#include "monsters.h" 


/* 
Function prototype: void place_mushrooms(Maze *maze, int num_mushrooms)
Function description: This function places a specified number of mushrooms at random unoccupied positions in the maze.
Parameter description: 
maze - A pointer to the Maze structure in which the mushrooms will be placed.
num_mushrooms - The number of mushrooms to place in the maze.
Return description: This function does not return a value.
*/
void place_mushrooms(Maze *maze, int num_mushrooms) {
    int i, x, y;
    for (i = 0; i < num_mushrooms; ++i) {
        do {
            x = rand() % maze->width;
            y = rand() % maze->height;
        } while (maze->elements[x][y].type != ' '); // Ensure the position is not occupied

        maze->elements[x][y].type = 'T';
    }
}

/* 
Function prototype: void place_coins(Maze *maze, int num_coins)
Function description: This function places a specified number of coins at random unoccupied positions in the maze.
Parameter description: 
maze - A pointer to the Maze structure in which the coins will be placed.
num_coins - The number of coins to place in the maze.
Return description: This function does not return a value.
*/
void place_coins(Maze *maze, int num_coins) {
    int i, x, y;
    for (i = 0; i < num_coins; ++i) {
        do {
            x = rand() % maze->width;
            y = rand() % maze->height;
        } while (maze->elements[x][y].type != ' '); // Ensure the position is not occupied

        maze->elements[x][y].type = 'C';
    }
}




/* Function prototype: Maze *new_maze(int width, int height,int num_monsters))
 * Function description: This function creates a new maze of a specified width and height, with walls around the edges and a start and end position.
 * Parameter description: 
 * width - The width of the new maze.
 * height - The height of the new maze.
 * Return description: This function returns a pointer to the newly created maze.
 */
Maze *new_maze(int width, int height, int num_monsters) {
    Maze *maze = (Maze *)malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->num_monsters = num_monsters;

    maze->elements = (Element **)malloc(width * sizeof(Element *));
    int x;
    for (x = 0; x < width; ++x) {
        maze->elements[x] = (Element *)malloc(height * sizeof(Element));
        int y;
        for (y = 0; y < height; ++y) {
            Element *elem = &(maze->elements[x][y]);
            elem->position.x = x;
            elem->position.y = y;
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                elem->type = 'w';
            } else {
                elem->type = ' ';
            }
        }
    }

    // Set start and end positions
    maze->elements[1][1].type = 'S';
    maze->elements[width - 2][height - 2].type = 'E';

    // Initialize monsters
    int i;
    for ( i = 0; i < num_monsters; ++i) {
        maze->monsters[i].position.x = 0;
        maze->monsters[i].position.y = 0;
    }

    return maze;
}

/* Function prototype: void make_accessible(Maze *maze, int x, int y)
 * Function description: This function ensures that all four directions (up, down, left, right) from a specified position in the maze are accessible.
 * Parameter description: 
 * maze - A pointer to the Maze structure which will be made accessible.
 * x - The x-coordinate of the position.
 * y - The y-coordinate of the position.
 * Return description: This function does not return a value.
 */
void make_accessible(Maze *maze, int x, int y) {
    // Direction array, representing up, down, left, right
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Traverse each direction
    int i,new_x,new_y;
    for ( i = 0; i < 4; ++i) {
        new_x = x + directions[i][0];
        new_y = y + directions[i][1];

        // Ensure the new position is within the maze boundary
        if (new_x >= 1 && new_x < maze->width - 1 && new_y >= 1 && new_y < maze->height - 1) {
            Element *elem = &maze->elements[new_x][new_y];

            // If this position is a wall, change it to a passage
            if (elem->type == 'w') {
                elem->type = ' ';
            }
        }
    }
}




/* Function prototype: void dfs_generate(Maze *maze, int x, int y, int *path, int *path_length)
 * Function description: This function uses depth-first search to generate a maze.
 * Parameter description: 
 * maze - A pointer to the Maze structure which will be generated.
 * x - The x-coordinate of the current position.
 * y - The y-coordinate of the current position.
 * path - An array representing the current path.
 * path_length - A pointer to an integer representing the length of the current path.
 * Return description: This function does not return a value.
 */
void dfs_generate(Maze *maze, int x, int y, int *path, int *path_length) {
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // 随机方向
    int i;
    for ( i = 3; i > 0; --i) {
        int r = rand() % (i + 1);
        int tmp_x = directions[i][0];
        int tmp_y = directions[i][1];
        directions[i][0] = directions[r][0];
        directions[i][1] = directions[r][1];
        directions[r][0] = tmp_x;
        directions[r][1] = tmp_y;
    }

    for ( i = 0; i < 4; ++i) {
        int new_x = x + directions[i][0] * 2;
        int new_y = y + directions[i][1] * 2;

        //已修复确定不会越界
        if (new_x >= 1 && new_x < maze->width - 1 && new_y >= 1 && new_y < maze->height - 1
            && maze->elements[new_x][new_y].type == 'w') {
            maze->elements[x + directions[i][0]][y + directions[i][1]].type = ' ';
            maze->elements[new_x][new_y].type = ' ';
            path[(*path_length)++] = new_x * maze->width + new_y;
            dfs_generate(maze, new_x, new_y, path, path_length);
        }
    }
}



/* 
原型: bool is_wall(Maze *maze, int x, int y)
功能描述: 判断给定坐标是否为墙
参数描述: Maze *maze: 迷宫的指针
          int x, y: 需要检查的坐标
返回值描述: 如果给定坐标的元素类型为墙，则返回 true，否则返回 false。

原型: void fix_doors(Maze *maze)
功能描述: 修复迷宫中所有门的位置，确保每个门都至少与两面墙相邻，且门后必有通道
参数描述: Maze *maze: 迷宫的指针
返回值描述: 无返回值
*/

bool is_passage(Maze *maze, int x, int y) {
    return x >= 0 && x < maze->width && y >= 0 && y < maze->height && maze->elements[x][y].type == ' ';
}

bool is_wall(Maze *maze, int x, int y) {
    return x >= 0 && x < maze->width && y >= 0 && y < maze->height && maze->elements[x][y].type == 'w';
}

void fix_doors(Maze *maze) {
    int dx[4] = {0, 1, 0, -1}; // right, down, left, up
    int dy[4] = {1, 0, -1, 0}; // down, right, up, left

    // Scan the entire maze
    int x,y,i,j;
    for ( x = 0; x < maze->width; ++x) {
        for ( y = 0; y < maze->height; ++y) {
            // If the current cell is a door
            if (maze->elements[x][y].type == 'D') {
                // Check the cells around the door
                int wall_count = 0;
                int passage_count = 0;
                for ( i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (is_wall(maze, nx, ny)) {
                        ++wall_count;
                    }
                    if (is_passage(maze, nx, ny)) {
                        ++passage_count;
                    }
                }

                // If there are less than two walls around the door, add walls
                if (wall_count < 2 || passage_count < 1) {
                    for ( i = 0; i < 4; ++i) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        // Ensure the position is within the maze boundary and does not contain important elements
                        if (nx >= 0 && nx < maze->width && ny >= 0 && ny < maze->height 
                            && maze->elements[nx][ny].type != 'D' && maze->elements[nx][ny].type != 'K') {
                            if (is_wall(maze, nx, ny) && wall_count < 2) {
                                maze->elements[nx][ny].type = 'w';
                                ++wall_count;
                            }
                            else if (is_passage(maze, nx, ny) && passage_count < 1) {
                                make_accessible(maze, nx, ny);
                                ++passage_count;
                            }
                            if (wall_count >= 2 && passage_count >= 1) {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}



/*随机放置门和钥匙函数*/
/*
函数原型: void place_keys_and_doors(Maze *maze, int num_keys, int num_doors, int *path, int path_length);
功能描述: 在给定的迷宫中随机放置指定数量的门和钥匙。
参数描述: 
  Maze *maze：指向迷宫结构的指针
  int num_keys：需要放置的钥匙的数量
  int num_doors：需要放置的门的数量
  int *path：表示迷宫路径的指针
  int path_length：路径的长度
返回值描述：该函数没有返回值
*/

void place_keys_and_doors(Maze *maze, int num_keys, int num_doors, int *path, int path_length) {
    int keys_added = 0;
    int doors_added = 0;
    int maze_width = maze->width;
    int maze_height = maze->height;
    char wall_type = 'w';
    char door_type = 'D';
    char key_type = 'K';
    char space_type = ' ';

    while (keys_added < num_keys || doors_added < num_doors) {
        if (doors_added < num_doors) {
            int door_x, door_y;
            do {
                // Randomly select a position to place the door
                door_x = rand() % (maze_width - 2) + 1;
                door_y = rand() % (maze_height - 2) + 1;
            } while (maze->elements[door_x][door_y].type != wall_type ||
                     door_x == 0 || door_y == 0 || 
                     door_x == maze_width - 1 || door_y == maze_height - 1 || 
                     !((maze->elements[door_x - 1][door_y].type == space_type && maze->elements[door_x + 1][door_y].type == space_type) || 
                       (maze->elements[door_x][door_y - 1].type == space_type && maze->elements[door_x][door_y + 1].type == space_type))); 

            // Check the door is not placed at the boundary and there is passage behind the door

            maze->elements[door_x][door_y].type = door_type;
            doors_added++;

            // Randomly select a position on the path to place the key
            int key_pos = rand() % path_length;
            int key_x = path[key_pos] / maze_width;
            int key_y = path[key_pos] % maze_width;
            maze->elements[key_x][key_y].type = key_type;
            keys_added++;
        } else {
            // Randomly place the remaining keys
            int rand_x = rand() % (maze_width - 2) + 1;
            int rand_y = rand() % (maze_height - 2) + 1;

            if (maze->elements[rand_x][rand_y].type == space_type) {
                maze->elements[rand_x][rand_y].type = key_type;
                keys_added++;
            }
        }
    }
    fix_doors(maze);
}







/*设置起点*/
/*
函数原型: void set_player_start_position(Maze *maze);
功能描述: 在迷宫的起始位置（1，1）设定玩家的起始点。
参数描述: 
  Maze *maze：指向迷宫结构的指针。
返回值描述：该函数没有返回值。
*/
void set_player_start_position(Maze *maze) {
    maze->elements[1][1].type = 'S';  // Set the start position
}


/*设置终点*/
/*
函数原型: void set_exit_position(Maze *maze);
功能描述: 在迷宫的右下角位置设定出口点。
参数描述: 
  Maze *maze：指向迷宫结构的指针。
返回值描述：该函数没有返回值。
*/
void set_exit_position(Maze *maze) {
    maze->elements[maze->width - 2][maze->height - 2].type = 'E';  // Set the exit position
}


/*地图生成函数*/ 
/*
函数原型: Maze *generate_random_maze(int width, int height, int num_keys, int num_doors,int num_mushrooms,int num_coins);
功能描述: 生成一个给定大小、包含特定数量的门、钥匙、蘑菇和硬币的随机迷宫。
参数描述: 
  int width：迷宫的宽度。
  int height：迷宫的高度。
  int num_keys：迷宫中钥匙的数量。
  int num_doors：迷宫中门的数量。
  int num_mushrooms：迷宫中蘑菇的数量。
  int num_coins：迷宫中硬币的数量。
返回值描述：返回一个指向新生成的迷宫的指针。
*/
Maze *generate_random_maze(int width, int height, int num_keys, int num_doors,int num_mushrooms,int num_coins) {
    // Ensure that width and height are odd numbers
    if (width % 2 == 0) {
        width++;
    }
    if (height % 2 == 0) {
        height++;
    }
    
    Maze *maze = new_maze(width, height,0);

    // Fill the maze with walls
    int x,y;
    for (x = 0; x < width; ++x) {
        for (y = 0; y < height; ++y) {
            maze->elements[x][y].type = 'w';
        }
    }

    // Generate the maze using DFS and record the path
    int *path = malloc(width * height * sizeof(int));
    int path_length = 0;
    dfs_generate(maze, 1, 1, path, &path_length);

    // Place the keys and doors
    place_keys_and_doors(maze, num_keys, num_doors, path, path_length);
    
    // Set the player start position
    set_player_start_position(maze);

    // Set the exit position
    set_exit_position(maze);
  
    place_mushrooms(maze,num_mushrooms);  
    place_coins(maze,num_coins);

    free(path);

    return maze;
}





/*函数原型: void save_maze(Maze *maze, const char *filename);
功能描述：将给定的迷宫保存到指定的文件中。
参数描述:
maze - 要保存的迷宫的指针。
filename - 要保存的文件的名字。
返回值描述：无。
*/
void save_maze(Maze *maze, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }
    int i,j;
    fprintf(file, "%d %d %d\n", maze->width, maze->height, maze->num_monsters);

    for (i = 0; i < maze->num_monsters; ++i) {
        fprintf(file, "%d %d\n", maze->monsters[i].position.x, maze->monsters[i].position.y);
    }


    for ( i = 0; i < maze->height; ++i) {
        for ( j = 0; j < maze->width; ++j) {
            fprintf(file, "%c", maze->elements[j][i].type ? maze->elements[j][i].type : ' '); 
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

/*函数原型: Maze *load_maze(const char *filename);
功能描述：从指定的文件中加载迷宫。
参数描述:
filename - 要加载的文件的名字。
返回值描述：返回加载的迷宫。如果加载失败，返回NULL。
*/
Maze *load_maze(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file '%s'.\n", filename);
        return NULL;
    }

    int width, height, num_monsters;
    fscanf(file, "%d %d %d\n", &width, &height, &num_monsters);

    Maze *maze = new_maze(width, height,num_monsters);
    int i;
    for ( i = 0; i < num_monsters; ++i) {
        int x, y;
        fscanf(file, "%d %d\n", &x, &y);
        maze->monsters[i].position.x = x;
        maze->monsters[i].position.y = y;
    }

    int y,x;
    for ( y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            char ch = fgetc(file);
            maze->elements[x][y].type = ch;
            maze->elements[x][y].position.x = x;
            maze->elements[x][y].position.y = y;

            if (ch == 'S') {
                maze->player.position.x = x;
                maze->player.position.y = y;
            }
        }
        fgetc(file); // Read newline character
    }

    fclose(file);
    return maze;
}
void change_elements(Maze *maze, int x, int y, char element) {
    if (x >= 0 && x < maze->width && y >= 0 && y < maze->height) {
    	if(element=='W'){
    	maze->elements[x][y].type = 'w';	
		}else{
		maze->elements[x][y].type = element;
		}
        
        // Debugging code:
        printf("Element at (%d, %d) changed to '%c'\n", x, y, maze->elements[x][y].type);
    } else {
        printf("Invalid coordinates: (%d, %d)\n", x, y);
    }
}


