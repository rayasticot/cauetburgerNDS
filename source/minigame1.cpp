#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <time.h>


#include "burgos.h"
#include "burger.h"

extern int win;

void minigame1(){
	win = -2;
	NF_MoveSprite(1, 0, 0*64, 192);
	NF_MoveSprite(1, 1, 1*64, 192);
	NF_MoveSprite(1, 2, 2*64, 192);
	NF_MoveSprite(1, 3, 3*64, 192);
	
	Burger bj0(4, 0, 0, 0);
	Burger bj1(5, 64, 32, 0);
	Burger bj2(6, 128, 64, 1);
	Burger bj3(7, 192, 96, 1);
	for(int i = 0; i < 300; i++){
		bj1.Check();
		bj2.Check();
		bj3.Check();
		bj0.Check();
		
		if(bj2.condition == true){
			win += 1;
		}
		if(bj0.condition == true){
			win -= 4;
		}
		if(bj1.condition == true){
			win -= 4;
		}
		if(bj3.condition == true){
			win += 1;
		}
		
		burgosLoop();
	}
	bj1.end();
	bj2.end();
	bj3.end();
	bj0.end();
}