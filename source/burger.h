#ifndef BURGER_H
#define BURGER_H

class Burger{
	private:
		int posx;
		int posy;
		int ids;
		void onClick(){
			NF_MoveSprite(1, ids, 256, 192);
			condition = true;
		};
	public:
		int condition = false;
		int types = 0;
		Burger(int id, int pos_x, int pos_y, int type){
			NF_CreateSprite(1, id, type, type, pos_x, pos_y);
			posx = pos_x;
			posy = pos_y;
			ids = id;
			types = type;
		};
		void Check(){
			if(KEY_TOUCH & keysDown()){
				if(Stylus.px >= posx){
					if(Stylus.px <= posx+64-types*32){
						if(Stylus.py >= posy){
							if(Stylus.py <= posy+32){
								onClick();
							}
						}
					}
				}
			}
		};
		void end(){
			NF_MoveSprite(1, ids, 256, 192);
		}
};
#endif