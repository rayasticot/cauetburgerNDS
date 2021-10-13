#ifndef ELEVATOR_H
#define ELEVATOR_H
void minigame1();
class elevator{
	private:
		int lives = 4;
		
	public:
		int winning = 0; //0 = tbd; 1 = loose; 2 = win
		elevator(){
			NF_CreateSprite(1, 0, 0, 0, 0*64, 0);
			NF_CreateSprite(1, 1, 0, 0, 1*64, 0);
			NF_CreateSprite(1, 2, 0, 0, 2*64, 0);
			NF_CreateSprite(1, 3, 0, 0, 3*64, 0);
		}
		void Update(){
			NF_MoveSprite(1, 0, 0*64, 192);
			NF_MoveSprite(1, 1, 1*64, 192);
			NF_MoveSprite(1, 2, 2*64, 192);
			NF_MoveSprite(1, 3, 3*64, 192);
			if(winning == 1){
				lives -= 1;
			}
			for(int i = 0; i < lives; ++i){
				NF_MoveSprite(1, i, i*64, 0);
			};
		};
};
#endif