#ifndef FUNCTION_HPP
#define FUNCTION_HPP
int seedGen();
void Elevator();
void minigame1();
void minigame2();
void minigame3();
void minigame4();
void mainLoop();
void loadSprite(int screen, char* url, int slot, int size_x, int size_y, bool anim);
void switchGame();
bool collisionCheck(int x, int y, int size_x, int size_y, int stylus_x, int stylus_y, int input);
#endif