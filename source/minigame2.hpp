#ifndef MINIGAME2_HPP
#define MINIGAME2_HPP
class Ball{
    private:
        int posx = 0;
        int posy = 0;
        int ids = 0;
        int idsa = 0;
        bool auth = true;
    public:
        Ball(int id){
            posx = rand() % 160 + 32;
            posy = rand() % 128 + 32;
            ids = id;
            switch(id){
                case 8:
                    idsa = 1;
                    break;
                case 9:
                    idsa = 2;
                    break;
                case 10:
                    idsa = 3;
                    break;
            }
            NF_CreateSprite(1, id, 2, 2, posx, posy);
        };
        void Check(){ // Qui est con
            if(collisionCheck(posx-32, posy-32, 64, 64, StylusB.px, StylusB.py, keysHeld()) == true){
                if(grab == 0){
                    grab = idsa;
                    posx = StylusB.px;
                    posy = StylusB.py;
                    NF_MoveSprite(1, ids, posx, posy);
                };
                if(idsa == grab){
                    posx = StylusB.px;
                    posy = StylusB.py;
                    NF_MoveSprite(1, ids, posx, posy);
                };
            }
            else{
                grab = 0;
            }
            if(posx <= hole_x+16){
                if(posy <= hole_y+16){
                    if(auth == true){
                        win += 1;
                        NF_ShowSprite(1, ids, false);
                        auth = false;
                    }
                }
            }
        }
};
#endif