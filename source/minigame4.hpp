#ifndef MINIGAME4_HPP
#define MINIGAME4_HPP
class Cauetattache{
    private:
        bool auth = true;
        void Move(int n){
            dir = n;
            y -= 5;
            NF_MoveSprite(1, 21, 32, y);
            NF_MoveSprite(1, 22, 96, y);
        }
    public:
        int y = 100;
        Cauetattache(){
            NF_CreateSprite(1, 21, 6, 6, 32, 100);
            NF_CreateSprite(1, 22, 5, 5, 96, 100);
        };
        void Check(){
            switch(dir){
                case 0:
                    if(KEY_LEFT & keysDown()){
                        Move(1);
                    }
                    break;
                case 1:
                    if(KEY_UP & keysDown()){
                        Move(2);
                    }
                    break;
                case 2:
                    if(KEY_RIGHT & keysDown()){
                        Move(3);
                    }
                    break;
                case 3:
                    if(KEY_DOWN & keysDown()){
                        Move(0);
                    }
                    break;
            }
            if(y < 36 && auth == true){
		        NF_PlayRawSound(2, 127, 64, false, 0);
                auth = false;
            }
        }
};
#endif