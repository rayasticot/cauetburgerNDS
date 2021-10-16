#ifndef DECLARATIONS_HPP
#define DECLARATIONS_HPP

void loadSprite(int screen, char* url, int slot, int size_x, int size_y, bool anim = false){
	
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
void switchGame(){
	NF_MoveSprite(1, 0, 0*64, 192);
	NF_MoveSprite(1, 1, 1*64, 192);
	NF_MoveSprite(1, 2, 2*64, 192);
	NF_MoveSprite(1, 3, 3*64, 192);
}
#endif