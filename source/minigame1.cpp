#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <time.h>

touchPosition StylusA;

#include "function.hpp"
#include "minigame1.hpp"


extern int win;
extern int flor;
int tim;

void minigame1(){
	NF_PlayRawSound(1, 127, 64, false, 0);
	NF_HideBg(1, 0);
	NF_ShowBg(1, 1);
	win = -2;
	switchGame();
	
	Burger bj0(4, 0);
	Burger bj1(5, 0);
	Burger bj2(6, 1);
	Burger bj3(7, 1);
	for(int i = 0; i < 210; i++){
		bj1.Check();
		bj2.Check();
		bj3.Check();
		bj0.Check();
		
		if(bj2.condition == true){
			win += 1;
			bj2.condition = false;
			if(win == 0){
				NF_PlayRawSound(2, 127, 64, false, 0);
			}
		}
		if(bj0.condition == true){
			win -= 4;
			bj0.condition = false;
		}
		if(bj1.condition == true){
			win -= 4;
			bj1.condition = false;
			
		}
		if(bj3.condition == true){
			win += 1;
			bj3.condition = false;
			if(win == 0){
				NF_PlayRawSound(2, 127, 64, false, 0);
			}
		}
		mainLoop();
		scanKeys();
		touchRead(&StylusA);

	}
	bj1.end();
	bj2.end();
	bj3.end();
	bj0.end();
	if(win < 0){
		NF_PlayRawSound(3, 127, 64, false, 0);
	}
}