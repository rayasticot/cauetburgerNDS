#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

touchPosition StylusC;
int seedpart[4];
int in = 0;
int buff;

#include "function.hpp"

int seedGen(){
    NF_WriteText(0, 1, 1, 1, "Appuyez 4 fois sur l'ecran pour generer une seed");
    NF_WriteText(0, 1, 1, 5, "Appuyez sur start pour avoir une seed de base");
	NF_UpdateTextLayers();
    while(1){
        mainLoop();
        scanKeys();
	    touchRead(&StylusC);
        if(KEY_TOUCH & keysDown()){
            seedpart[in] = StylusC.px;
            in += 1;
        }
        if(KEY_START & keysDown()){
            buff = 142;
            break;
        }
        if(in == 4){
            buff = seedpart[0]+seedpart[1]+seedpart[2]+seedpart[3];
            break;
        }
    }
    NF_ClearTextLayer(0, 1);
	NF_UpdateTextLayers();
    return buff;
}