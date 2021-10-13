#ifndef BURGOS_H
#define BURGOS_H

touchPosition Stylus;

void burgosLoop(){

	NF_SpriteOamSet(0);
	NF_SpriteOamSet(1);
	swiWaitForVBlank();

	oamUpdate(&oamMain);
	oamUpdate(&oamSub);
	
	scanKeys();
	touchRead(&Stylus);

}
#endif