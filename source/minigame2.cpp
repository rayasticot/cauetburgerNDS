#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <time.h>

touchPosition StylusB;
int hole_x = 16;
int hole_y = 16;
int grab;
extern int win;

#include "ball.hpp"
#include "function.hpp"


void minigame2(){
    win = -2;
    NF_PlayRawSound(1, 127, 64, false, 0);
    NF_CreateSprite(1, 11, 2, 3, hole_x, hole_y);
    switchGame();
    NF_HideBg(1, 0);
	NF_ShowBg(1, 1);
    Ball bal1(8);
    Ball bal2(9);

    for(int i = 0; i < 210; i++){
        bal1.Check();
        bal2.Check();
        mainLoop();
        scanKeys();
	    touchRead(&StylusB);
    }
    NF_DeleteSprite(1, 8);
    NF_DeleteSprite(1, 9);
    NF_DeleteSprite(1, 11);
}