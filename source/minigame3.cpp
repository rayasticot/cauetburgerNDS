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
    Tuyo ty1(13, 256, 0);
    Tuyo ty2(14, 256, 128);
    Tuyo ty3(15, 128, 32);
    Tuyo ty4(16, 128, 160);

    for(int i = 0; i < 400; i++){
        fl.t = i;
        fl.Check();
        ty1.Check();
        ty2.Check();
        ty3.Check();
        ty4.Check();
        mainLoop();
        scanKeys();
    }
}