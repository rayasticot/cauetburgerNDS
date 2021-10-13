#ifndef BURGOS_HPP
#define BURGOS_HPP
touchPosition Stylus;

void burgosLoop(){
	
	scanKeys();
	touchRead(&Stylus);

}
#endif