#ifndef MONSTERS_H
#define MONSTERS_H

#define MAX_MONSTERS 100 // define maximum number of monsters

#include"solve.h"
// Function declarations
void clear_walls_around_position(Maze *maze, Position pos);
void generate_monster_in_maze(Monster *monster, Maze *maze);
Monster *generate_monsters_in_maze(Maze *maze, int num_monsters);
void move_monster(Monster *monster, Maze *maze,int order);
void move_monsters(Maze *maze);

#endif // MONSTERS_H

