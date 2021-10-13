#ifndef ULYSSE_H
#define ULYSSE_H

void Elevator();
void minigame1();

void loadSprite(int screen, char* url, int slot, int size_x, int size_y){
	
	NF_LoadSpriteGfx(url, slot, size_x, size_y);
	NF_LoadSpritePal(url, slot);
	NF_VramSpriteGfx(screen, slot, slot, false);
	NF_VramSpritePal(screen, slot, slot);
	
}
void mainLoop(){
	
		NF_SpriteOamSet(0);
		NF_SpriteOamSet(1);

		swiWaitForVBlank();

		oamUpdate(&oamMain);
		oamUpdate(&oamSub);

}
#endif