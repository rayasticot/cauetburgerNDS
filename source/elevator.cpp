#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

#include "function.hpp"

#include "elevator.hpp"

int win = -2;
int flor = 0;

void elevatorLoop();
void flip(bool oio);

int time = 0;
int frame = 0;
char text[9];
bool rev = false;
bool skip = false;

void Elevator(){
	elevator eleve;
	while(1){
		NF_PlayRawSound(0, 127, 64, false, 0);
		NF_ShowBg(1, 0);
		sprintf(text, "floor %d", flor);
		NF_WriteText(0, 0, 1, 1, text);
		NF_UpdateTextLayers();
		eleve.Update();
		flor += 1;
		time = 0;
		
		while(time < 120){
			elevatorLoop();
		}
		minigame1();
		if(win >= 0){
			eleve.winning = 2;
		}
		else{
			eleve.winning = 1;
		}
	}
	
}
void elevatorLoop(){
	mainLoop();
	time += 1;
	if(skip == false){
		if(frame == 7){
			rev = true;
			flip(true);
		}
		if(frame == 0){
			rev = false;
			flip(false);
		}
		if(rev == false){
			frame += 1;
		}
		else{
			frame -= 1;
		}
		NF_SpriteFrame(1, 0, frame);
		NF_SpriteFrame(1, 1, frame);
		NF_SpriteFrame(1, 2, frame);
		NF_SpriteFrame(1, 3, frame);
		skip = true;
	}
	else{
		skip = false;
	}
}
void flip(bool oio){
	NF_HflipSprite(1, 0, oio);
	NF_HflipSprite(1, 1, oio);
	NF_HflipSprite(1, 2, oio);
	NF_HflipSprite(1, 3, oio);
}