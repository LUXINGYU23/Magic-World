#include"display.h"
void ClearDisplay() {
    HWND hwnd = GetActiveWindow(); // Get the handle of the active window
    if (hwnd != NULL) {
        InvalidateRect(hwnd, NULL, TRUE); // Invalidate the entire window
    }
}

void draw_maze(Maze *maze, double start_x, double start_y, double width, double height) {
	double cell_width=width/maze->width;
	double cell_height=height/maze->height;
    char *bmp_files[9] = {"picture/rock1.bmp", "picture/rock2.bmp", "picture/rock3.bmp", "picture/rock.bmp", "picture/rock5.bmp", "picture/flower3.bmp", "picture/flower1.bmp", "picture/flower4.bmp","picture/flower2.bmp"};
    int x,y;
    for ( x = 0; x < maze->width; ++x) {
        for ( y = 0; y < maze->height; ++y) {
            double draw_x = start_x + x * cell_width;
            double draw_y = start_y + y * cell_height;
            if (maze->elements[x][y].type == 'w') {
                srand(x * maze->width + y);
                int bmp_index = rand() % 9;
                draw_bmp(bmp_files[bmp_index], draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == ' ') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'T') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
                draw_bmp("picture/mushroom.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'C') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
                draw_bmp("picture/coin.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'K') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
                draw_bmp("picture/key.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'D') {
                draw_bmp("picture/door.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'O') {
                draw_bmp("picture/opened door.bmp", draw_x, draw_y, cell_width, cell_height);
            }
        }
    }
    // Draw the player
    if(direction==1){
    	draw_bmp("picture/player1.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
	}
	if(direction==2){
    	draw_bmp("picture/player2.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
	}
	if(direction==3){
    	draw_bmp("picture/player3.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
	}
	if(direction==4){
    	draw_bmp("picture/player4.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
    }
    
    // Draw monsters
    int i;
    for ( i = 0; i < maze->num_monsters; ++i) {
        draw_bmp("picture/monster.bmp",start_x + maze->monsters[i].position.x * cell_width, start_y + maze->monsters[i].position.y * cell_height, cell_width, cell_height);
    }
}




void draw_maze_with_path(Maze *maze, Solution *solution, double start_x, double start_y, double width, double height) {
	double cell_width=width/maze->width;
	double cell_height=height/maze->height;
    char *bmp_files[9] = {"picture/rock1.bmp", "picture/rock2.bmp", "picture/rock3.bmp", "picture/rock.bmp", "picture/rock5.bmp", "picture/flower3.bmp", "picture/flower1.bmp", "picture/flower4.bmp","picture/flower2.bmp"};
    int x, y;
    for ( x = 0; x < maze->width; ++x) {
        for ( y = 0; y < maze->height; ++y) {
            double draw_x = start_x + x * cell_width;
            double draw_y = start_y + y * cell_height;
            if (maze->elements[x][y].type == 'w') {
                srand(x * maze->width + y);
                int bmp_index = rand() % 9;
                draw_bmp(bmp_files[bmp_index], draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == ' ') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'T') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
                draw_bmp("picture/mushroom.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'C') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
                draw_bmp("picture/coin.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'K') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
                draw_bmp("picture/key.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'D') {
                draw_bmp("picture/door.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'O') {
                draw_bmp("picture/opened door.bmp", draw_x, draw_y, cell_width, cell_height);
            }
        }
    }
    int i;
    for (i = 0; i < solution->length; ++i) {
        draw_bmp("picture/path.bmp", start_x + solution->path[i].x * cell_width, start_y + solution->path[i].y * cell_height, cell_width, cell_height);
    }

    // Draw the player
    if(direction==1){
    	draw_bmp("picture/player1.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
	}
	if(direction==2){
    	draw_bmp("picture/player2.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
	}
	if(direction==3){
    	draw_bmp("picture/player3.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
	}
	if(direction==4){
    	draw_bmp("picture/player4.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
    }
    
    // Draw monsters
    for ( i = 0; i < maze->num_monsters; ++i) {
        draw_bmp("picture/monster.bmp", start_x + maze->monsters[i].position.x * cell_width, start_y + maze->monsters[i].position.y * cell_height, cell_width, cell_height);
    } 
}


void draw_maze_with_next_path(Maze *maze, Solution *solution, double start_x, double start_y, double width, double height) {
	double cell_width=width/maze->width;
	double cell_height=height/maze->height;
    char *bmp_files[9] = {"picture/rock1.bmp", "picture/rock2.bmp", "picture/rock3.bmp", "picture/rock.bmp", "picture/rock5.bmp", "picture/flower3.bmp", "picture/flower1.bmp", "picture/flower4.bmp","picture/flower2.bmp"};
    int x, y;
    for ( x = 0; x < maze->width; ++x) {
        for ( y = 0; y < maze->height; ++y) {
            double draw_x = start_x + x * cell_width;
            double draw_y = start_y + y * cell_height;
            if (maze->elements[x][y].type == 'w') {
                srand(x * maze->width + y);
                int bmp_index = rand() % 9;
                draw_bmp(bmp_files[bmp_index], draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == ' ') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'T') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
                draw_bmp("picture/mushroom.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'C') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
                draw_bmp("picture/coin.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'K') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
                draw_bmp("picture/key.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'D') {
                draw_bmp("picture/door.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'O') {
                draw_bmp("picture/opened door.bmp", draw_x, draw_y, cell_width, cell_height);
            }
        }
    }
    int i;
    for (i = 0; i < 1; ++i) {
        draw_bmp("picture/path.bmp", start_x + solution->path[i].x * cell_width, start_y + solution->path[i].y * cell_height, cell_width, cell_height);
    }

    // Draw the player
    if(direction==1){
    	draw_bmp("picture/player1.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
	}
	if(direction==2){
    	draw_bmp("picture/player2.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
	}
	if(direction==3){
    	draw_bmp("picture/player3.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
	}
	if(direction==4){
    	draw_bmp("picture/player4.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
    }
    
    // Draw monsters
    for ( i = 0; i < maze->num_monsters; ++i) {
        draw_bmp("picture/monster.bmp", start_x + maze->monsters[i].position.x * cell_width, start_y + maze->monsters[i].position.y * cell_height, cell_width, cell_height);
    } 
}


void draw_maze_with_path_and_auto_move(Maze *maze, Solution *solution, double start_x, double start_y, double width, double height) {
	double cell_width=width/maze->width;
	double cell_height=height/maze->height;
    char *bmp_files[9] = {"picture/rock1.bmp", "picture/rock2.bmp", "picture/rock3.bmp", "picture/rock.bmp", "picture/rock5.bmp", "picture/flower3.bmp", "picture/flower1.bmp", "picture/flower4.bmp","picture/flower2.bmp"};
    int x, y;
    for ( x = 0; x < maze->width; ++x) {
        for ( y = 0; y < maze->height; ++y) {
            double draw_x = start_x + x * cell_width;
            double draw_y = start_y + y * cell_height;
            if (maze->elements[x][y].type == 'w') {
                srand(x * maze->width + y);
                int bmp_index = rand() % 9;
                draw_bmp(bmp_files[bmp_index], draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == ' ') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'T') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
                draw_bmp("picture/mushroom.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'C') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
                draw_bmp("picture/coin.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'K') {
                draw_bmp("picture/td.bmp", draw_x, draw_y, cell_width, cell_height);
                draw_bmp("picture/key.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'D') {
                draw_bmp("picture/door.bmp", draw_x, draw_y, cell_width, cell_height);
            }
            else if (maze->elements[x][y].type == 'O') {
                draw_bmp("picture/opened door.bmp", draw_x, draw_y, cell_width, cell_height);
            }
        }
    }
    int i;
    for (i = 0; i < solution->length; ++i) {
        draw_bmp("picture/path.bmp", start_x + solution->path[i].x * cell_width, start_y + solution->path[i].y * cell_height, cell_width, cell_height);
    }
    
    maze->player.position.x=solution->path[0].x;
    maze->player.position.y=solution->path[0].y;
    check_collision(maze, maze->player.position);
    // Draw the player
    if(direction==1){
    	draw_bmp("picture/player1.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
	}
	if(direction==2){
    	draw_bmp("picture/player2.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
	}
	if(direction==3){
    	draw_bmp("picture/player3.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
	}
	if(direction==4){
    	draw_bmp("picture/player4.bmp",start_x + maze->player.position.x * cell_width, start_y + maze->player.position.y * cell_height, cell_width, 0.1+cell_height);
    }
    
    // Draw monsters
    for ( i = 0; i < maze->num_monsters; ++i) {
        draw_bmp("picture/monster.bmp", start_x + maze->monsters[i].position.x * cell_width, start_y + maze->monsters[i].position.y * cell_height, cell_width, cell_height);
    } 
    
}










