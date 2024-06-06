#include"scene.h"
#include"graphics.h"
void draw_array(const char arr[5][5],int q) {
    int startX = 3.7;  // ��ʼX����
    int startY = 3.8;  // ��ʼY����
    int offset = 2; // ÿ��ͼ��֮���ƫ����
    if(q==1){
        startY=startY+1;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char current = arr[i][j];
            double x = startX + j * offset;  // ���㵱ǰλ�õ�X����
            double y = startY + i * offset;  // ���㵱ǰλ�õ�Y����
            switch (current) {
                case 'G':
                    draw_bmp("picture/rock1.bmp", x, y, 1, 1);
                    break;
                case 'Y':
                    draw_bmp("picture/flower3.bmp", x, y, 1, 1);
                    break;
                case 'R':
                    draw_bmp("picture/flower1.bmp", x, y, 1, 1);
                    break;
                case 'T':
                    draw_bmp("picture/flower5.bmp", x, y, 1, 1);
                    break;
                case 'a':
                   draw_bmp("picture/a.bmp", x, y, 1, 1);
                    break;
                case 'b':
                   draw_bmp("picture/b.bmp", x, y, 1, 1);
                   break;
                case 'c':
                   draw_bmp("picture/c.bmp", x, y, 1, 1);
                    break;
                case 'd':
                   draw_bmp("picture/d.bmp", x, y, 1, 1);
                    break;
                case 'e':
                   draw_bmp("picture/e.bmp", x, y, 1, 1);
                    break;
                case 'f':
                   draw_bmp("picture/f.bmp", x, y, 1, 1);
                    break;
                case 'g':
                   draw_bmp("picture/g.bmp", x, y, 1, 1);
                    break;
                case 'h':
                   draw_bmp("picture/h.bmp", x, y, 1, 1);
                    break;
                case 'i':
                   draw_bmp("picture/i.bmp", x, y, 1, 1);
                    break;
                case 'j':
                   draw_bmp("picture/j.bmp", x, y, 1, 1);
                    break;
                case 'k':
                   draw_bmp("picture/k.bmp", x, y, 1, 1);
                    break;
                case 'l':
                   draw_bmp("picture/l.bmp", x, y, 1, 1);
                   break;
                case 'm':
                   draw_bmp("picture/m.bmp", x, y, 1, 1);
                    break;
                case 'n':
                   draw_bmp("picture/n.bmp", x, y, 1, 1);
                    break;
                case 'o':
                   draw_bmp("picture/o.bmp", x, y, 1, 1);
                    break;
                case 'p':
                   draw_bmp("picture/p.bmp", x, y, 1, 1);
                    break;
                case 'q':
                   draw_bmp("picture/q.bmp", x, y, 1, 1);
                    break;
                case 'r':
                   draw_bmp("picture/r.bmp", x, y, 1, 1);
                    break;
                case 's':
                   draw_bmp("picture/s.bmp", x, y, 1, 1);
                    break;
                case 't':
                   draw_bmp("picture/t.bmp", x, y, 1, 1);
                    break;
                case 'u':
                   draw_bmp("picture/u.bmp", x, y, 1, 1);
                    break;
                case 'v':
                   draw_bmp("picture/v.bmp", x, y, 1, 1);
                    break;
                case 'w':
                   draw_bmp("picture/w.bmp", x, y, 1, 1);
                    break;
                case 'x':
                   draw_bmp("picture/x.bmp", x, y, 1, 1);
                    break;
                case 'y':
                   draw_bmp("picture/y.bmp", x, y, 1, 1);
                    break;
                case 'z':
                   draw_bmp("picture/z.bmp", x, y, 1, 1);
                    break;
                default:
                    break;
            }
        }
    }
    printf("sussess\n");
}
void init_Array(char arr[5][5],int q) {
    if(q==0){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = 'G';  // ��ÿ��Ԫ������Ϊ'G'
        }
    }
    }else{
        for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = '\0';  // ��ÿ��Ԫ������Ϊ'G'
        }
    }
    }
}
/*���Ʊ������*/ 
void DrawInitialSurface() 
{   
    
    draw_bmp("picture/titlepicture.bmp",0,0,17,15);
    draw_bmp("picture/magicmaze.bmp",1,3,15,2);
    buttonList[1] = CreateImageButton("picture/startword.bmp", 6, 8, 5, 1, 1); 
    buttonList[2] = CreateImageButton("picture/setting.bmp", 16, 0, 1, 1, 2); //������ͣ��ť 
    scene=1;//������� 

}
/*����NPC����*/ 
void DrawNPCSurface()
{
	draw_bmp("picture/start.bmp",0,0,17,15);
	draw_bmp("picture/npc.bmp",8.5,6,1,1);
	draw_bmp("picture/npc2.bmp",4,2,1,1) ;//���Ʋʵ�npc  
    draw_bmp("picture/player.bmp",11.4,6,1,1);
	scene=2;//npc���� 
	maze->player.position.x=8.5;
    maze->player.position.y=12;
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
} 

/*����ѡ�񴴽����߼��ص�ͼ����*/ 
void randomOrManualChoose(){
	draw_bmp("picture/background3.bmp",0,0,17,15);
	buttonList[51] = CreateImageButton("picture/random.bmp",3,4,5,5,51);
	buttonList[52] = CreateImageButton("picture/manual.bmp",9,4,5,5,52);
	draw_bmp("picture/�����������.bmp",3,10,5,3);
	draw_bmp("picture/�ֶ��༭����.bmp",9,10,5,3);
}
/*����ѡ���ѶȽ���*/ 
void DrawPickmodeSurface()
{
	scene=3; 
	DestroyButton(buttonList[2]);
	draw_bmp("picture/background.bmp",0,0,17,15);
	buttonList[9] = CreateImageButton("picture/hard.bmp", 1, 4, 6, 1.5, 9); 
	buttonList[10] = CreateImageButton("picture/normal.bmp", 1, 6.5, 6, 1.5, 10);
	buttonList[11] = CreateImageButton("picture/easy.bmp", 1, 9, 6, 1.5, 11);
	buttonList[12] = CreateImageButton("picture/confirm.bmp", 9.5, 12, 5, 1.5, 12);
} 

/*�����ֶ��༭��ͼ����*/ 
void draw_scene_edit_maze(){
    scene=5;//�༭��ͼ���� 
	draw_bmp("picture/background.bmp",0,0,17,15);
	draw_bmp("picture/background2.bmp",0,0,11.5,11.5);	
	buttonList[20] = CreateImageButton("picture/check.bmp",14.5,7,1,1,20); //����ȷ����ť  ��ȷ�ϣ������޸Ĳ��������ص���ǰ���棩 
	buttonList[21] = CreateImageButton("picture/startbutton.bmp",5,12,7,3,21); //���ƿ�ʼ��ť �������Թ���ͼ��  
	buttonList[23] = CreateImageButton("picture/save.bmp",14.5,5,1,1,23);//���Ʊ��水ť 
	draw_bmp("picture/��.bmp",11.5,4,1,1);
	draw_bmp("picture/��.bmp",11.5,6,1,1);
	draw_bmp("picture/��.bmp",13.5,4,1,1);
	draw_bmp("picture/��.bmp",13.5,6,1,1);
	draw_bmp("picture/˵��.bmp",12.5,9,4,4);
	textboxList[1]=CreateTextBox(12.5,4,1,1,91); //����X�����������ı��� 
	textboxList[2]=CreateTextBox(12.5,6,1,1,92); //����Y�����������ı��� 
	textboxList[3]=CreateTextBox(12.5,8,1,1,93); //�����滻Ԫ���ı��� 
	draw_maze(maze,1.0,1.0,9.0,9.0);	
}
/*�����Թ���Ϸ��������*/ 
void draw_scene_mazegame(){
	scene=6;//�Թ���ͼ��Ϸ���� 
    draw_bmp("picture/background.bmp",0,0,17,15);
    draw_bmp("picture/rock.bmp",15.0,4.0,1,1);
    draw_bmp("picture/rock4.bmp",16.0,4.0,0.75,1.5);
    draw_bmp("picture/zl.bmp",14.0,2.0,4,4);
    draw_bmp("picture/tree1.bmp",15.0,2.0,2,2); 
    draw_bmp("picture/tree2.bmp",15.0,6.0,2,2); 
    draw_bmp("picture/flower6.bmp",0.0,2.0,1,1); 
    draw_bmp("picture/mushrooms.bmp",14.0,8.0,1.5,0.75); 
    draw_bmp("picture/rock5.bmp",16.0,7.6,1.5,1.5);
    draw_bmp("picture/Trees1.bmp",14.0,9,4,2.1);
    draw_bmp("picture/Trees2.bmp",14.0,11,4,2.1);
    draw_bmp("picture/Trees.bmp",14.0,13,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,3,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,4,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,5,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,6,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,7,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,8,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,9,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,10,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,11,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,12,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,13,4,2.1);
    draw_maze(maze,2.0,2.0,12.0,12.0); // Draw the maze
    draw_bmp("picture/Trees1.bmp",0.0,13.1,4,2.1);
    draw_bmp("picture/Trees.bmp",2.0,13.1,4,2.1);
    draw_bmp("picture/Trees1.bmp",5.0,13.1,4,2.1);
    draw_bmp("picture/Trees2.bmp",8.0,13.1,4,2.1);
    draw_bmp("picture/Trees3.bmp",11.0,13.1,4,2.1);
    draw_bmp("picture/Trees2.bmp",14.0,13.1,4,2.1);
    draw_life(maze->player.life);
    draw_keys(maze->player.keys);
    draw_wealth(maze->player.wealth);
} 

/*���������ʾ״̬���Թ���Ϸ��������*/ 
void draw_scene_mazegame_with_path(Solution *solution){
	scene=6;//�Թ���ͼ��Ϸ���� 
    draw_bmp("picture/background.bmp",0,0,17,15);
    draw_bmp("picture/rock.bmp",15.0,4.0,1,1);
    draw_bmp("picture/rock4.bmp",16.0,4.0,0.75,1.5);
    draw_bmp("picture/zl.bmp",14.0,2.0,4,4);
    draw_bmp("picture/tree1.bmp",15.0,2.0,2,2); 
    draw_bmp("picture/tree2.bmp",15.0,6.0,2,2); 
    draw_bmp("picture/flower6.bmp",0.0,2.0,1,1); 
    draw_bmp("picture/mushrooms.bmp",14.0,8.0,1.5,0.75); 
    draw_bmp("picture/rock5.bmp",16.0,7.6,1.5,1.5);
    draw_bmp("picture/Trees1.bmp",14.0,9,4,2.1);
    draw_bmp("picture/Trees2.bmp",14.0,11,4,2.1);
    draw_bmp("picture/Trees.bmp",14.0,13,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,3,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,4,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,5,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,6,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,7,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,8,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,9,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,10,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,11,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,12,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,13,4,2.1);  
    draw_maze_with_path(maze,solution,2.0,2.0,12.0,12.0); // Draw the maze
    draw_bmp("picture/Trees1.bmp",0.0,13.1,4,2.1);
    draw_bmp("picture/Trees.bmp",2.0,13.1,4,2.1);
    draw_bmp("picture/Trees1.bmp",5.0,13.1,4,2.1);
    draw_bmp("picture/Trees2.bmp",8.0,13.1,4,2.1);
    draw_bmp("picture/Trees3.bmp",11.0,13.1,4,2.1);
    draw_bmp("picture/Trees2.bmp",14.0,13.1,4,2.1);
	draw_life(maze->player.life);
    draw_keys(maze->player.keys);
    draw_wealth(maze->player.wealth);
    freeSolution(solution);//�ͷ�solution 
}
/*���������ʾ��һ��״̬���Թ���Ϸ��������*/ 
void draw_scene_mazegame_with_next_path(Solution *solution){
	scene=6;//�Թ���ͼ��Ϸ���� 
    draw_bmp("picture/background.bmp",0,0,17,15);
    draw_bmp("picture/rock.bmp",15.0,4.0,1,1);
    draw_bmp("picture/rock4.bmp",16.0,4.0,0.75,1.5);
    draw_bmp("picture/zl.bmp",14.0,2.0,4,4);
    draw_bmp("picture/tree1.bmp",15.0,2.0,2,2); 
    draw_bmp("picture/tree2.bmp",15.0,6.0,2,2); 
    draw_bmp("picture/flower6.bmp",0.0,2.0,1,1); 
    draw_bmp("picture/mushrooms.bmp",14.0,8.0,1.5,0.75); 
    draw_bmp("picture/rock5.bmp",16.0,7.6,1.5,1.5);
    draw_bmp("picture/Trees1.bmp",14.0,9,4,2.1);
    draw_bmp("picture/Trees2.bmp",14.0,11,4,2.1);
    draw_bmp("picture/Trees.bmp",14.0,13,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,3,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,4,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,5,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,6,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,7,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,8,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,9,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,10,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,11,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,12,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,13,4,2.1);  
    draw_maze_with_next_path(maze,solution,2.0,2.0,12.0,12.0); // Draw the maze
    draw_bmp("picture/Trees1.bmp",0.0,13.1,4,2.1);
    draw_bmp("picture/Trees.bmp",2.0,13.1,4,2.1);
    draw_bmp("picture/Trees1.bmp",5.0,13.1,4,2.1);
    draw_bmp("picture/Trees2.bmp",8.0,13.1,4,2.1);
    draw_bmp("picture/Trees3.bmp",11.0,13.1,4,2.1);
    draw_bmp("picture/Trees2.bmp",14.0,13.1,4,2.1);
	draw_life(maze->player.life);
    draw_keys(maze->player.keys);
    draw_wealth(maze->player.wealth);
    freeSolution(solution);//�ͷ�solution 
}


/*�������״̬���Թ���Ϸ��������*/ 
void draw_scene_mazegame_with_auto_path(Solution *solution){
	scene=9;//�Թ���ͼ��Ϸ���� 
    draw_bmp("picture/background.bmp",0,0,17,15);
    draw_bmp("picture/rock.bmp",15.0,4.0,1,1);
    draw_bmp("picture/rock4.bmp",16.0,4.0,0.75,1.5);
    draw_bmp("picture/zl.bmp",14.0,2.0,4,4);
    draw_bmp("picture/tree1.bmp",15.0,2.0,2,2); 
    draw_bmp("picture/tree2.bmp",15.0,6.0,2,2); 
    draw_bmp("picture/flower6.bmp",0.0,2.0,1,1); 
    draw_bmp("picture/mushrooms.bmp",14.0,8.0,1.5,0.75); 
    draw_bmp("picture/rock5.bmp",16.0,7.6,1.5,1.5);
    draw_bmp("picture/Trees1.bmp",14.0,9,4,2.1);
    draw_bmp("picture/Trees2.bmp",14.0,11,4,2.1);
    draw_bmp("picture/Trees.bmp",14.0,13,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,3,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,4,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,5,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,6,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,7,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,8,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,9,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,10,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,11,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,12,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,13,4,2.1);  
    draw_maze_with_path_and_auto_move(maze,solution,2.0,2.0,12.0,12.0); // Draw the maze
    draw_bmp("picture/Trees1.bmp",0.0,13.1,4,2.1);
    draw_bmp("picture/Trees.bmp",2.0,13.1,4,2.1);
    draw_bmp("picture/Trees1.bmp",5.0,13.1,4,2.1);
    draw_bmp("picture/Trees2.bmp",8.0,13.1,4,2.1);
    draw_bmp("picture/Trees3.bmp",11.0,13.1,4,2.1);
    draw_bmp("picture/Trees2.bmp",14.0,13.1,4,2.1);
	draw_life(maze->player.life);
    draw_keys(maze->player.keys);
    draw_wealth(maze->player.wealth);
    freeSolution(solution);//�ͷ�solution 
    
}
/*���Ʋʵ�����*/ 
void draw_scene_game_egg(){
	scene=8;//�ʵ����� 
//	buttonList[2] = CreateImageButton("picture/setting.bmp", 16, 0, 1, 1, 2); //������ͣ��ť 
	draw_bmp("picture/start.bmp",0,0,17,15);
	draw_bmp("picture/egg.bmp",8.5,6,1,2);//���Ʋʵ�npc 
    draw_bmp("picture/talk.bmp",7.5,5,1,1);
	maze->player.position.x=8.5;
    maze->player.position.y=12;
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
	
	
} 
void draw_scene_about_developers(){
	draw_bmp("picture/background.bmp",0.0,0.0,17,15);
	
} 

/*����ʤ������*/ 
void DrawVictory(){
	draw_bmp("picture/background5.bmp",0,0,17,15);
	draw_bmp("picture/victory.bmp",1.5,4,14,3);
	buttonList[13] = CreateImageButton("picture/back.bmp", 7.5,13 , 2, 2, 13); //���Ʒ��ذ�ť 
}
/*����ʧ�ܽ���*/ 
void DrawDefeat(){
	draw_bmp("picture/background5.bmp",0,0,17,15);
	draw_bmp("picture/defeat.bmp",1.5,4,14,3);
	buttonList[13] = CreateImageButton("picture/back.bmp", 7.5,13 , 2, 2, 13); //���Ʒ��ذ�ť 
}

/*�����������ֵ*/ 
void draw_life(int life){
	double cell_width =0.55;
    double cell_height = 0.55 ;
    int x;
	for(x=0;x<life;x++){
		draw_bmp("picture/life.bmp",x*cell_width,0,cell_width,cell_height);
	} 
    
}
/*�������Կ����*/ 
void draw_keys(int key){
	double cell_width =0.55;
    double cell_height = 0.55 ;
    int x;
	for(x=0;x<key;x++){
		draw_bmp("picture/key.bmp",x*cell_width,0.6,cell_width,cell_height);
	} 
	
}

/*������ҲƸ�ֵ*/ 
void draw_wealth(int wealth){
	double cell_width =0.55;
    double cell_height = 0.55 ;
    int x;
	for(x=0;x<wealth;x++){
		draw_bmp("picture/coin.bmp",x*cell_width,1.2,cell_width,cell_height);
	} 
	
}

/*�趨���״̬����*/ 
void set_player(int key,int life ) {
	maze->player.life=life;
	maze->player.keys=key;
	maze->player.wealth=0;
}

/*����Wordle����*/
//��ʼ������
void init_wordle(){
    scene=20;//Wordle�����ʶ��
    DestroyButton(buttonList[2]);//������ͣ��ť
    draw_bmp("picture/background.bmp",0,0,17,15);//���Ա�����ͼ
    //----�д����-----//
    //������ͼ����ť�������ı���ȵĻ���//
    //��ӦWordle.c����жϺ���������ӻ�����//
    //��ذ�ťת���߼�,��graphics.c���ʵ��-1099��//
    draw_bmp("picture/background.bmp",0,0,17,15);
    draw_bmp("picture/rock.bmp",15.0,4.0,1,1);
    draw_bmp("picture/rock4.bmp",16.0,4.0,0.75,1.5);
    draw_bmp("picture/zl.bmp",14.0,2.0,4,4);
    draw_bmp("picture/tree1.bmp",15.0,2.0,2,2); 
    draw_bmp("picture/tree2.bmp",15.0,6.0,2,2); 
    draw_bmp("picture/flower6.bmp",0.0,2.0,1,1); 
    draw_bmp("picture/mushrooms.bmp",14.0,8.0,1.5,0.75); 
    draw_bmp("picture/rock5.bmp",16.0,7.6,1.5,1.5);
    draw_bmp("picture/Trees1.bmp",14.0,9,4,2.1);
    draw_bmp("picture/Trees2.bmp",14.0,11,4,2.1);
    draw_bmp("picture/Trees.bmp",14.0,13,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,3,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,4,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,5,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,6,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,7,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,8,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,9,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,10,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,11,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,12,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,13,4,2.1);
    draw_bmp("picture/Trees1.bmp",0.0,13.1,4,2.1);
    draw_bmp("picture/Trees.bmp",2.0,13.1,4,2.1);
    draw_bmp("picture/Trees1.bmp",5.0,13.1,4,2.1);
    draw_bmp("picture/Trees2.bmp",8.0,13.1,4,2.1);
    draw_bmp("picture/Trees3.bmp",11.0,13.1,4,2.1);
    draw_bmp("picture/Trees2.bmp",14.0,13.1,4,2.1);
    draw_bmp("picture/wordle.bmp",6.5,0.5,5.5,2.5);
    init_Array(wordle_array,0); //��ʼ������
    init_Array(wordle_current,1);
    draw_array(wordle_array,0); //��������
    draw_bmp("picture/input.bmp",12.6,6.6,1,0.3);
    textboxList[4]=CreateTextBox(12.6,7,1,0.5,94); //����X�����������ı��� 
    buttonList[60] = CreateImageButton("picture/check.bmp",12.6,7.7,1,1,60); //����ȷ����ť
    buttonList[61] = CreateImageButton("picture/back.bmp",0,0,1,1,61);
}
//��Ϸ����ʱ���������ݴ���ȽϽ���������
void game_wordle(){
    scene=20;//Wordle�����ʶ��
    draw_bmp("picture/background.bmp",0,0,17,15);//���Ա�����ͼ
    //----�д����-----//
    //������ͼ����ť�������ı���ȵĻ���//
    //��ӦWordle.c����жϺ���������ӻ�����//
    //��ذ�ťת���߼�,��graphics.c���ʵ��-1099��//
    draw_bmp("picture/background.bmp",0,0,17,15);
    draw_bmp("picture/rock.bmp",15.0,4.0,1,1);
    draw_bmp("picture/rock4.bmp",16.0,4.0,0.75,1.5);
    draw_bmp("picture/zl.bmp",14.0,2.0,4,4);
    draw_bmp("picture/tree1.bmp",15.0,2.0,2,2); 
    draw_bmp("picture/tree2.bmp",15.0,6.0,2,2); 
    draw_bmp("picture/flower6.bmp",0.0,2.0,1,1); 
    draw_bmp("picture/mushrooms.bmp",14.0,8.0,1.5,0.75); 
    draw_bmp("picture/rock5.bmp",16.0,7.6,1.5,1.5);
    draw_bmp("picture/Trees1.bmp",14.0,9,4,2.1);
    draw_bmp("picture/Trees2.bmp",14.0,11,4,2.1);
    draw_bmp("picture/Trees.bmp",14.0,13,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,3,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,4,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,5,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,6,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,7,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,8,4,2.1);
    draw_bmp("picture/Trees1.bmp",-2,9,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,10,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,11,4,2.1);
    draw_bmp("picture/Trees2.bmp",-2,12,4,2.1);
    draw_bmp("picture/Trees.bmp",-2,13,4,2.1);
    draw_bmp("picture/Trees1.bmp",0.0,13.1,4,2.1);
    draw_bmp("picture/Trees.bmp",2.0,13.1,4,2.1);
    draw_bmp("picture/Trees1.bmp",5.0,13.1,4,2.1);
    draw_bmp("picture/Trees2.bmp",8.0,13.1,4,2.1);
    draw_bmp("picture/Trees3.bmp",11.0,13.1,4,2.1);
    draw_bmp("picture/Trees2.bmp",14.0,13.1,4,2.1);
    draw_bmp("picture/wordle.bmp",6.5,0.5,5.5,2.5);
    draw_array(wordle_array,0); //�������� 
    draw_array(wordle_current,1);//������������
    draw_bmp("picture/input.bmp",12.6,6.6,1,0.3);
    textboxList[4]=CreateTextBox(12.6,7,1,0.5,94); //����X�����������ı��� 
    buttonList[60] = CreateImageButton("picture/check.bmp",12.6,7.7,1,1,60); //����ȷ����ť
    buttonList[61] = CreateImageButton("picture/back.bmp",0,0,1,1,61);
}
