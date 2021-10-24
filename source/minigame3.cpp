#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

int ground_y = 180;
extern int win;

#include "function.hpp"
#include "minigame3.hpp"

void minigame3(){
    win = 1;
    NF_PlayRawSound(1, 127, 64, false, 0);
    switchGame();
    NF_HideBg(1, 0);
	NF_ShowBg(1, 1);

    Fly fl;

    Tuyo ty1(13, 256, 0);
    Tuyo ty2(14, 256, 32);
    Tuyo ty3(15, 256, 128);
    Tuyo ty4(16, 256, 160);

    Tuyo ty5(17, 384, 0);
    Tuyo ty6(18, 384, 96);
    Tuyo ty7(19, 384, 128);
    Tuyo ty8(20, 384, 160);

    Tuyo ty9(17, 512, 0);
    Tuyo ty10(18, 512, 32);
    Tuyo ty11(19, 512, 64);
    Tuyo ty12(20, 512, 160);


    for(int i = 0; i < 400; i++){  // Les array la sa ne passe pas
        fl.t = i;
        fl.Check();
        
        ty1.Check();
        ty2.Check();
        ty3.Check();
        ty4.Check();

        ty5.Check();
        ty6.Check();
        ty7.Check();
        ty8.Check();

        ty9.Check();
        ty10.Check();
        ty11.Check();
        ty12.Check();

        mainLoop();
        scanKeys();
    }
        
    ty1.End();
    ty2.End();
    ty3.End();
    ty4.End();

    ty5.End();
    ty6.End();
    ty7.End();
    ty8.End();


    fl.End();

}