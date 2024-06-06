#ifndef DISPLAY_H
#define DISPLAY_H
#include<windows.h>
#include<stdio.h>
#include"solve.h"
#include"graphics.h"
#include "wordle.h"

void ClearDisplay(); //���������draw_mazeʵ����Ļˢ�� 
void draw_maze(Maze *maze, double start_x, double start_y, double width, double height);//�����Թ���ͼ 
void draw_maze_with_path(Maze *maze, Solution *solution, double start_x, double start_y, double width, double height);//���ƴ��н�·�����Թ� 
void draw_maze_edit(Maze *maze);
void draw_maze_with_next_path(Maze *maze, Solution *solution, double start_x, double start_y, double width, double height);
void draw_maze_with_path_and_auto_move(Maze *maze, Solution *solution, double start_x, double start_y, double width, double height);

#endif
