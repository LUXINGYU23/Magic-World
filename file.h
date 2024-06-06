#ifndef FILE_H
#define FILE_H
#define MAX_MONSTERS 100 // define maximum number of monsters
#include "solve.h"
#include "monsters.h" 
#include "wordle.h"


// �ļ�����ģ��
Maze *load_maze(const char *filename);//���ص�ͼ 
void save_maze(Maze *maze, const char *filename);//�����ͼ
//void exit_game();//δ������װ������ع����Ѿ�ʵ�� 

// ��ͼ�༭ģ��
void change_elements(Maze *maze, int x, int y, char element); 
Maze *generate_random_maze(int width, int height, int num_keys, int num_doors,int num_mushrooms,int num_coins);//���������ͼ 

#endif // FILE_H

