#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

int ground_y = 180;


#include "function.hpp"
#include "minigame3.hpp"

void minigame3(){
    NF_PlayRawSound(1, 127, 64, false, 0);
    switchGame();
    NF_HideBg(1, 0);
	NF_ShowBg(1, 1);
    Fly fl;
    Tuyo ty1(0, 13);

    for(int i = 0; i < 400; i++){
        fl.t = i;
        fl.Check();
        ty1.Check();
        mainLoop();
        scanKeys();
    }
}