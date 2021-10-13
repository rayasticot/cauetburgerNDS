#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <time.h>

#include "ulysse.h"

int main(int argc, char **argv) {
	
	/* Fonctions pour tout initialiser */
	NF_Set2D(0, 0);
	NF_Set2D(1, 0);
	NF_SetRootFolder("NITROFS");
	NF_InitSpriteBuffers();
	NF_InitSpriteSys(0);
	NF_InitSpriteSys(1);
	
	loadSprite(1, "cauettourne", 0, 64, 32); // charge un sprite
	loadSprite(1, "anelka", 1, 32, 32);
	
	Elevator();
	
	
	while(1) {

		NF_Error(0, "ulysse", 0);
	
	}

	return 0; 

}
