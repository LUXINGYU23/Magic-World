#ifndef DISPLAY_H
#define DISPLAY_H
#include<windows.h>
#include<stdio.h>
#include"solve.h"
#include"graphics.h"

void ClearDisplay(); //清屏，配合draw_maze实现屏幕刷新 
void draw_maze(Maze *maze, double start_x, double start_y, double width, double height);//绘制迷宫地图 
void draw_maze_with_path(Maze *maze, Solution *solution, double start_x, double start_y, double width, double height);//绘制带有解路径的迷宫 
void draw_maze_edit(Maze *maze);
void draw_maze_with_next_path(Maze *maze, Solution *solution, double start_x, double start_y, double width, double height);
void draw_maze_with_path_and_auto_move(Maze *maze, Solution *solution, double start_x, double start_y, double width, double height);

#endif
