#ifndef SOLVE_H
#define SOLVE_H

#define MAX_MONSTERS 100 // define maximum number of monsters

#include <stdbool.h>
#include<stdio.h>
#include "wordle.h"

// Position structure
typedef struct {
    int x, y;
} Position;

// Player structure
typedef struct {
    Position position;
    int life;
    int keys;
    int wealth;
} Player;

// Monster structure
typedef struct {
    Position position;
    int direction; // 0: up, 1: right, 2: down, 3: left
} Monster;

// Element structure
typedef struct {
    Position position;
    char type; // 'w': wall, 'S': start, 'E': end, 'K': key, 'D': door,"O":Opened door ,'T' for mushroom, 'C' for coin
} Element;

// Maze structure
typedef struct {
    int width, height;
    Player player;
    Monster monsters[MAX_MONSTERS];
    int num_monsters;
    Element **elements;
} Maze;

// Solution structure
typedef struct {
    Position *path;
    int length;
} Solution;

typedef struct SolutionNode {
    Solution solution;
    struct SolutionNode *next;
} SolutionNode;

typedef struct {
    SolutionNode *head;
    int count;
} SolutionList;
extern int height,width,num_keys,num_doors;
extern int num_mushrooms,num_coins,num_monsters;
extern int direction;
extern Maze *maze;
extern int musicmode;
extern SolutionList solution_list;
// Manual solve module
void move_player(Maze *maze, int dx, int dy);//ʵ��������Թ���ͼ�е�λ�õı仯������dx������dy 
void move_player2(Maze *maze, int dx, int dy); //ʵ�����������������λ�õı仯������dx������dy 
bool check_collision(Maze *maze, Position newPosition);//��ײ��� 
bool check_victory(Maze *maze);//�������Ƿ�ﵽ�յ�ʤ�� 

// Program solve module (BFS algorithm)
Solution *find_shortest_path(Maze *maze);//�ҵ����·�� ������solution 


// Hint module
Position *next_step_hint(Maze *maze);//��ʾ��һ�� 


void solve_maze(Maze *maze, SolutionList *solution_list);
void free_solution_list(SolutionList *solution_list);
void freeSolution(Solution *solution);
void freeMaze(Maze *maze); 
void print_solutions(SolutionList *solution_list);

#endif // SOLVE_H

