#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include "solve.h" 
#include "file.h"
#include "monsters.h"
#include "display.h"
#include "scene.h"
#include "wordle.h"
#define TIMER_ID_REFRESH 0 
#define TIMER_ID_MONSTER_MOVE 1


#define TIMER_INTERVAL 10 // Set timer interval to 10 ms 


void KeyboardEvent(int key, int event);//�����¼����� 
void TimerEvent(int timer);//ʱ���¼����� 
Maze *maze;//�����Թ���ͼ�ṹ�� 
SolutionList solution_list;//�����Թ��������ṹ 
int height,width,num_keys,num_doors;//�����Թ��������� 
int num_mushrooms,num_coins,num_monsters;
int scene=0; //��ʼ��ȫ�ֳ������� 
int mode=0; //��ʼ��ȫ��ģʽ���� 
int inmenu=0;
int musicmode=1; 
int direction=1;//��ʼ��ȫ����ҷ��� 

void Main() //��ʼ��ͼ�ν��棬����ʼ��һ�� 
{   
	PlaySound (TEXT("picture/stage_01.wav"),NULL,SND_FILENAME | SND_ASYNC|SND_LOOP |SND_NODEFAULT);
    srand(time(NULL));//������������� 
	maze = generate_random_maze(10,10,0,0,0,0);//��ʼ���Թ���ͼ 
    SetWindowSize(17,15);//���ô��ڴ�С 
    InitGraphics();//��ʼ��ͼ�ν��� 
 // InitConsole();//��ʼ������̨���� 
    set_player(1,5);
    DrawInitialSurface();//������ʼ���� 
    registerKeyboardEvent(KeyboardEvent); // ע����̻ص����� 
    startTimer(0, TIMER_INTERVAL); // ��ʼһ��ʱ�� 
    registerTimerEvent(TimerEvent); // ע��ʱ��ص����� 
	
}

void KeyboardEvent(int key, int event)
{
    if (event != KEY_DOWN) return; 
    if(ButtonChoice==1&&scene==2){ //����2�¼����߼� 
    int dx=0,dy=0;
    switch (key) {
        case VK_UP:
            dy=-1;
            direction=4;
            break;
        case VK_DOWN:
            dy=1;
            direction=1;
            break;
        case VK_LEFT:
            dx=-1;
            direction=3;
            break;
        case VK_RIGHT:
            dx=1;
            direction=2;
            break;
    }
    move_player2(maze,dx,dy);
    ClearDisplay();
    draw_bmp("picture/start.bmp",0,0,17,15);
    draw_bmp("picture/npc.bmp",8.5,6,1,1);
    draw_bmp("picture/npc2.bmp",4,2,1,1) ; 
    draw_bmp("picture/talk.bmp",7.5,5,1,1);
    draw_bmp("picture/player.bmp",11.4,6,1,1);
	if(direction==1){
    	draw_bmp("picture/player1.bmp",maze->player.position.x * 1,  maze->player.position.y * 1, 1,1.5);
	}
	if(direction==2){
    	draw_bmp("picture/player2.bmp",maze->player.position.x * 1,  maze->player.position.y * 1, 1,1.5);
	}
	if(direction==3){
    	draw_bmp("picture/player3.bmp",maze->player.position.x * 1,  maze->player.position.y * 1, 1,1.5);
	}
	if(direction==4){
    	draw_bmp("picture/player4.bmp",maze->player.position.x * 1,  maze->player.position.y * 1, 1,1.5);
    }
    if(key==VK_TAB){
    	if(maze->player.position.x>=7.5&&maze->player.position.x<=9.5&&maze->player.position.y>=5&&maze->player.position.y<=7) {
				draw_bmp("picture/box.bmp",0, 11, 17, 4);
				draw_bmp("picture/word.bmp",4, 11, 10, 3);
				ButtonChoice=2;
				buttonList[8] = CreateImageButton("picture/yes.bmp", 14, 14, 2, 1, 8); 
				DestroyButton(buttonList[2]);//����2��ť
			}
			if(maze->player.position.x>=3.5&&maze->player.position.x<=5.5&&maze->player.position.y>=1&&maze->player.position.y<=3) {
//               draw_scene_game_egg();
			}
//-----------wordle����������----------------//            
            if(maze->player.position.x>=9.5&&maze->player.position.x<=11.5&&maze->player.position.y>=5&&maze->player.position.y<=7) {
               
               init_wordle();
			}
	
		
	}
	}else if(ButtonChoice==1&&scene==6){//����6�¼����߼� 
	int dx=0,dy=0;
    int isDraw_maze_with_path=0;
    int isDraw_maze_all_path=0;
    int isDraw_maze_with_next_path=0;
    switch (key) {
        case VK_UP:
            dy=-1;
            direction=4;
            break;
        case VK_DOWN:
            dy=1;
            direction=1;
            break;
        case VK_LEFT:
            dx=-1;
            direction=3;
            break;
        case VK_RIGHT:
            dx=1;
            direction=2;
            break;
        case VK_RETURN://������·����ʾ 
            isDraw_maze_with_path=1;
            break;
        case VK_SPACE://������н� 
            if(mode==3){
            isDraw_maze_all_path=1;
			} 
			break;
		case VK_TAB:
			isDraw_maze_with_next_path=1;
    }
	move_player(maze,dx,dy);
	move_monsters(maze);
    check_collision(maze, maze->player.position);
    ClearDisplay();
    if( isDraw_maze_with_path==0&&isDraw_maze_with_next_path==0){
    	draw_scene_mazegame();
	}else if(isDraw_maze_with_path==1&&isDraw_maze_with_next_path==0){
		draw_scene_mazegame_with_path(find_shortest_path(maze));
	}else if(isDraw_maze_with_path==0&&isDraw_maze_with_next_path==1){
		draw_scene_mazegame_with_next_path(find_shortest_path(maze));
	}
	
	if(isDraw_maze_all_path==1){
		InitConsole();
		solve_maze(maze, &solution_list); //��� 
        print_solutions(&solution_list);
	    free_solution_list(&solution_list);//�ͷ�����
	    FreeConsole();
	}
	if(maze->player.life<=0){
		ClearDisplay();
    	DestroyButton(buttonList[2]);
    	DestroyButton(buttonList[80]);
    	ButtonChoice=2;
    	DrawDefeat();
	}
	if(check_victory(maze)){
    ClearDisplay();
    DestroyButton(buttonList[2]);
    DestroyButton(buttonList[80]);
    ButtonChoice=2;
    DrawVictory();	
	}  
}
    if(ButtonChoice==1&&scene==8){ //����8�¼����߼� 
    int dx=0,dy=0;
    switch (key) {
        case VK_UP:
            dy=-1;
            direction=4;
            break;
        case VK_DOWN:
            dy=1;
            direction=1;
            break;
        case VK_LEFT:
            dx=-1;
            direction=3;
            break;
        case VK_RIGHT:
            dx=1;
            direction=2;
            break;
    }
    move_player2(maze,dx,dy);
    ClearDisplay();
    draw_bmp("picture/start.bmp",0,0,17,15);
   draw_bmp("picture/egg.bmp",8.5,6,1,2);//���Ʋʵ�npc 
   draw_bmp("picture/talk.bmp",7.5,5,1,1);
	if(direction==1){
    	draw_bmp("picture/player1.bmp",maze->player.position.x * 1,  maze->player.position.y * 1, 1,1.5);
	}
	if(direction==2){
    	draw_bmp("picture/player2.bmp",maze->player.position.x * 1,  maze->player.position.y * 1, 1,1.5);
	}
	if(direction==3){
    	draw_bmp("picture/player3.bmp",maze->player.position.x * 1,  maze->player.position.y * 1, 1,1.5);
	}
	if(direction==4){
    	draw_bmp("picture/player4.bmp",maze->player.position.x * 1,  maze->player.position.y * 1, 1,1.5);
    }
    if(key==VK_TAB){
    	if(maze->player.position.x>=7.5&&maze->player.position.x<=9.5&&maze->player.position.y>=5&&maze->player.position.y<=7) {
				draw_bmp("picture/box.bmp",0, 11, 17, 4);//���Ʋʵ� �Ի����� 
				draw_bmp("picture/egg1.bmp",0,11,4,4);
				draw_bmp("picture/word1.bmp",4, 11, 10, 3);
				ButtonChoice=2;
				buttonList[40] = CreateImageButton("picture/yes.bmp", 14, 14, 2, 1, 40);
				DestroyButton(buttonList[2]);//����2��ť 
			}
	}
} 
}


int frameCount6 = 0;
int frameCount9 = 0;
void TimerEvent(int timer)
{

	if(ButtonChoice==1&&scene==6){//����6��ˢ���߼� 
    // Move monsters less frequently
    if (frameCount6 % 200 == 0) {
    move_monsters(maze);
    ClearDisplay();
    draw_scene_mazegame();
    if(maze->player.life==0){
		ClearDisplay();
    	DestroyButton(buttonList[2]);
    	DestroyButton(buttonList[80]);
    	ButtonChoice=2;
    	DrawDefeat();
	}
	}
    frameCount6++;
}
	if(ButtonChoice==3&&scene==9){//������ⳡ����ʱ��ص��߼� 
	if (frameCount9 % 100 == 0) {
    ClearDisplay();
    draw_scene_mazegame_with_auto_path(find_shortest_path(maze));
    if(check_victory(maze)){
    DisplayClear();
    DestroyButton(buttonList[81]);
    DestroyButton(buttonList[82]);
    DestroyButton(buttonList[83]);
    DestroyButton(buttonList[84]);
    ButtonChoice=2;
    DrawVictory();	
	}
	}
	frameCount9++;
	}
}


