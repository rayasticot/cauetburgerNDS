#ifndef MINIGAME1_HPP
#define MINIGAME1_HPP

class Burger{
	private:
		int posx = rand() % 192;
		int posy = rand() % 160;
		int ids;
		bool auth = true;
		void onClick(){
			NF_MoveSprite(1, ids, 256, 192);
			condition = true;
			auth = false;
		};
	public:
		int condition = false;
		int types = 0;
		Burger(int id, int type){
			NF_CreateSprite(1, id, type, type, posx, posy);
			ids = id;
			types = type;
		};
		void Check(){
			if(collisionCheck(posx, posy, 32+32*types, 32, StylusA.px, StylusA.py, keysHeld()) == true){
				if(auth == true){
					onClick();
				}
			}
		};
		void end(){
			NF_MoveSprite(1, ids, 256, 192);
		}
};
#endif