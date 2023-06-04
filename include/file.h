#ifndef FILE_H
#define FILE_H
#define MAX_MONSTERS 100 // define maximum number of monsters
#include "solve.h"
#include "monsters.h" 



// 文件操作模块
Maze *load_maze(const char *filename);//加载地图 
void save_maze(Maze *maze, const char *filename);//保存地图
//void exit_game();//未独立封装，但相关功能已经实现 

// 地图编辑模块
void change_elements(Maze *maze, int x, int y, char element); 
Maze *generate_random_maze(int width, int height, int num_keys, int num_doors,int num_mushrooms,int num_coins);//随机创建地图 

#endif // FILE_H

