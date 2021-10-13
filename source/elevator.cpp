#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

#include "elevator.h"

int win = -2;

void elevatorLoop();
void flip(bool oio);
void ElevatorRegular();

int time = 0;
int frame = 0;
bool rev = false;
bool skip = false;

void Elevator(){
	
	ElevatorRegular();
	
}
void ElevatorRegular(){
	elevator eleve;
	while(1){
		eleve.Update();
		time = 0;
		while(time < 300){
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
	NF_SpriteOamSet(0);
	NF_SpriteOamSet(1);

	swiWaitForVBlank();

	oamUpdate(&oamMain);
	oamUpdate(&oamSub);
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