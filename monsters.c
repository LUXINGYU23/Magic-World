#include"monsters.h"
#include<time.h>
#include<math.h>
/*函数原型: void clear_walls_around_position(Maze *maze, Position pos);
功能描述：清除给定位置周围一格范围内的墙壁。
参数描述:
maze - 迷宫的指针。
pos - 需要清除周围墙壁的位置。
返回值描述：无。
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

/*函数原型: void generate_monster_in_maze(Monster *monster, Maze *maze);
功能描述：在迷宫中随机生成一个怪物。
参数描述:
monster - 怪物的指针。
maze - 迷宫的指针。
返回值描述：无。
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

/*函数原型: Monster *generate_monsters_in_maze(Maze *maze, int num_monsters);
功能描述：在迷宫中随机生成指定数量的怪物。
参数描述:
maze - 迷宫的指针。
num_monsters - 需要生成的怪物数量。
返回值描述：返回生成的怪物的数组。
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

/*函数原型: void move_monster(Monster *monster, Maze *maze,int order);
功能描述：移动迷宫中的一个怪物。
参数描述:
monster - 需要移动的怪物的指针。
maze - 迷宫的指针。
order - 怪物的移动次序，用于确定随机的移动方向。
返回值描述：无。
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

/*函数原型: void move_monsters(Maze *maze);
功能描述：移动迷宫中的所有怪物。
参数描述:
maze - 迷宫的指针。
返回值描述：无。
*/
void move_monsters(Maze *maze) {
	int i;
    for ( i = 0; i < maze->num_monsters; ++i) {
        move_monster(&maze->monsters[i], maze,i);
    }
}

