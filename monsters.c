#include"monsters.h"
#include<time.h>
#include<math.h>
/*����ԭ��: void clear_walls_around_position(Maze *maze, Position pos);
�����������������λ����Χһ��Χ�ڵ�ǽ�ڡ�
��������:
maze - �Թ���ָ�롣
pos - ��Ҫ�����Χǽ�ڵ�λ�á�
����ֵ�������ޡ�
*/
void clear_walls_around_position(Maze *maze, Position pos) {
	int dx,dy;
    for ( dx = -1; dx <= 1; ++dx) {
        for ( dy = -1; dy <= 1; ++dy) {
            int x = pos.x + dx;
            int y = pos.y + dy;

            // Ensure the position is within the maze boundary
            if (x > 0 && x < maze->width - 1 && y > 0 && y < maze->height - 1) {
                if (maze->elements[x][y].type == 'w' || maze->elements[x][y].type == 'D') {
                    maze->elements[x][y].type = ' ';
                }
            }
        }
    }
}

/*����ԭ��: void generate_monster_in_maze(Monster *monster, Maze *maze);
�������������Թ����������һ�����
��������:
monster - �����ָ�롣
maze - �Թ���ָ�롣
����ֵ�������ޡ�
*/
void generate_monster_in_maze(Monster *monster, Maze *maze) {
    Position monster_position;
    do {
        monster_position.x = rand() % maze->width;
        monster_position.y = rand() % maze->height;
    } while (maze->elements[monster_position.x][monster_position.y].type != ' ');

    int monster_direction = rand() % 4;
    monster->position = monster_position;
    monster->direction = monster_direction;
}

/*����ԭ��: Monster *generate_monsters_in_maze(Maze *maze, int num_monsters);
�������������Թ����������ָ�������Ĺ��
��������:
maze - �Թ���ָ�롣
num_monsters - ��Ҫ���ɵĹ���������
����ֵ�������������ɵĹ�������顣
*/
Monster *generate_monsters_in_maze(Maze *maze, int num_monsters) {
    if (num_monsters > MAX_MONSTERS) {
        num_monsters = MAX_MONSTERS;
    }

    maze->num_monsters = num_monsters;
    int i;
    for ( i = 0; i < num_monsters; ++i) {
        // Generate a monster at a random position
        generate_monster_in_maze(&maze->monsters[i], maze);

        // Clear the walls around the monster
        clear_walls_around_position(maze, maze->monsters[i].position);
    }

    return maze->monsters;
}

/*����ԭ��: void move_monster(Monster *monster, Maze *maze,int order);
�����������ƶ��Թ��е�һ�����
��������:
monster - ��Ҫ�ƶ��Ĺ����ָ�롣
maze - �Թ���ָ�롣
order - ������ƶ���������ȷ��������ƶ�����
����ֵ�������ޡ�
*/
void move_monster(Monster *monster, Maze *maze,int order) {
    srand(time(NULL));
    Position curr_position = monster->position;
    int direction = ((int)(rand() * pow(3, order))) % 4; // Randomly select a direction
    Position next_position = curr_position;
    switch (direction) {
        case 0: // up
            next_position.y--;
            break;
        case 1: // right
            next_position.x++;
            break;
        case 2: // down
            next_position.y++;
            break;
        case 3: // left
            next_position.x--;
            break;
    }

    if (maze->elements[next_position.x][next_position.y].type == 'w'||maze->elements[next_position.x][next_position.y].type == 'D') {
        monster->direction = (direction + 2) % 4; // Reverse direction if the monster hits a wall
    } else {
        monster->position = next_position;
        monster->direction = direction; // Update the monster's direction
    }
}

/*����ԭ��: void move_monsters(Maze *maze);
�����������ƶ��Թ��е����й��
��������:
maze - �Թ���ָ�롣
����ֵ�������ޡ�
*/
void move_monsters(Maze *maze) {
	int i;
    for ( i = 0; i < maze->num_monsters; ++i) {
        move_monster(&maze->monsters[i], maze,i);
    }
}

