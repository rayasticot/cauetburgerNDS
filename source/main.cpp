#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

#include "declarations.hpp"
#include "function.hpp"

int main(int argc, char **argv) {
	
	/* Fonctions pour tout initialiser */
	NF_Set2D(0, 0);
	NF_Set2D(1, 0);
	NF_SetRootFolder("NITROFS");
	NF_InitSpriteBuffers();
	NF_InitSpriteSys(0);
	NF_InitSpriteSys(1);

	NF_InitTiledBgBuffers();
	NF_InitTiledBgSys(0);
	NF_InitTiledBgSys(1);

	NF_LoadTiledBg("bg/cauetburger", "cauetfont", 256, 256);
	NF_CreateTiledBg(1, 0, "cauetfont");
	NF_LoadTiledBg("bg/green", "green", 256, 256);
	NF_CreateTiledBg(1, 1, "green");
	NF_ShowBg(1, 0);

	NF_InitTextSys(0);
	NF_LoadTextFont("fnt/default", "default", 256, 256, 0);
	NF_CreateTextLayer(0, 0, 0, "default");
	NF_CreateTextLayer(0, 1, 0, "default");
	
	int seed = seedGen();

	soundEnable();
	NF_InitRawSoundBuffers();
	NF_LoadRawSound("snd/next", 0, 11025, 0);
	NF_LoadRawSound("snd/stage", 1, 11025, 0);
	NF_LoadRawSound("snd/haha", 2, 11025, 0);
	NF_LoadRawSound("snd/oh", 3, 11025, 0);

	loadSprite(1, "spr/cauettourne", 0, 64, 32, true); // charge un sprite
	loadSprite(1, "spr/anelka", 1, 32, 32);
	loadSprite(1, "spr/ball", 2, 16, 16);
	loadSprite(1, "spr/maison", 4, 32, 64);
	loadSprite(1, "spr/cauetfly2", 5, 64, 64);
	loadSprite(1, "spr/cauetfly3", 6, 64, 64);
	loadSprite(1, "spr/croix", 7, 32, 32);

	NF_LoadSpriteGfx("spr/point", 8, 16, 16);
	NF_LoadSpritePal("spr/croix", 8);
	NF_VramSpriteGfx(1, 8, 8, false);
	NF_VramSpritePal(1, 8, 8);

	NF_LoadSpritePal("spr/black", 3);
	NF_VramSpritePal(1, 3, 3);
	
	srand(seed);

	Elevator(); //Elevator.cpp
	
	
	while(1) {

		NF_Error(0, "ulysse", 0);
	
	}

	return 0; 
}
