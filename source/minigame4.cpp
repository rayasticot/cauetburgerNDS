#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <time.h>

extern int win;
int dir = 0;
int pisx[4] = {224, 235, 248, 235};
int pisy[4] = {172, 161, 172, 183};

#include "function.hpp"
#include "minigame4.hpp"


void minigame4(){
    win = -2;
    NF_PlayRawSound(1, 127, 64, false, 0);
    switchGame();
    NF_HideBg(1, 0);
	NF_ShowBg(1, 1);
    NF_CreateSprite(1, 24, 8, 8, pisx[0], pisy[0]);
    NF_CreateSprite(1, 23, 7, 7, 224, 160);
    Cauetattache cauet;

    for(int i = 0; i < 210; i++){
        mainLoop();
        scanKeys();
        cauet.Check();
        NF_MoveSprite(1, 24, pisx[dir], pisy[dir]);
    }
    if(cauet.y < 36){
        win = 0;
    }
    else{
		NF_PlayRawSound(3, 127, 64, false, 0);
    }
    NF_DeleteSprite(1, 21);
    NF_DeleteSprite(1, 22);
    NF_DeleteSprite(1, 23);
    NF_DeleteSprite(1, 24);
}