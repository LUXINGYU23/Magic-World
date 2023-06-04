#ifndef SCENE_H
#define SCENE_H


#include "solve.h" 
#include "file.h"
#include "monsters.h"
#include "display.h"
#include "graphics.h"
// Function declarations
void DrawInitialSurface() ;
void DrawNPCSurface();
void randomOrManualChoose();
void DrawPickmodeSurface();
void draw_scene_edit_maze();
void draw_scene_mazegame();
void draw_scene_mazegame_with_path(Solution *solution);
void draw_scene_game_egg();
void DrawVictory();
void DrawDefeat();
void draw_life(int life);
void draw_keys(int key);
void draw_wealth(int wealth);
void set_player(int key,int life);
void draw_scene_mazegame_with_next_path(Solution *solution);
void draw_scene_mazegame_with_auto_path(Solution *solution);


#endif // SCENE_H
