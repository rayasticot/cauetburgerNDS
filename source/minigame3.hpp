#ifndef MINIGAME3_HPP
#define MINIGAME3_HPP
class Fly{
    private:
        int y = 100;
        double speed = 0.5;
        int acc_y = -15;
        bool stuck = false;
        const int u_y[6] = {0, 128, 0, 96, 0, 160};
    public:
        int x = 112;
        double t = 0;
        Fly(){
            NF_CreateSprite(1, 12, 2, 2, x, y);
        };
        void Check(){
            t = t/60;
            y += acc_y*speed;
            acc_y += 1;
            if(KEY_TOUCH & keysDown()){
                acc_y = -10;
            }
            if(y >= ground_y){
                win = -2;
                stuck = true;
            }
            if(stuck == false){
                NF_MoveSprite(1, 12, x, y);
            }
            switch(status){
                case 0:
                    if(y < 64 || y > 128){
                        if(x > poins[0] && x < poins[0]+32){
                            win = -2;
                            stuck = true;
                            NF_MoveSprite(1, 12, 256, 192);
                        }
                    }
                    break;
                case 1:
                    if(y < 32 || y > 96){
                        if(x > poins[1] && x < poins[1]+32){
                            win = -2;
                            stuck = true;
                            NF_MoveSprite(1, 12, 256, 192);
                        }
                    }
                    break;
                case 2:
                    if(y < 96 || y > 160){
                        if(x > poins[2] && x < poins[2]+32){
                            win = -2;
                            stuck = true;
                            NF_MoveSprite(1, 12, 256, 192);
                        }
                    }
                    break;
                    /* if(y < u_y[2] || y > u_y[2]+64){
                        if(x > poins[2] && x < poins[2]+32){
                            win = -2;
                            stuck = true;
                        }
                    } */
            }
            if(y < 0){
                y = 0;
            }
        };
        void End(){
            NF_DeleteSprite(1, 12);
        }
};
class Tuyo{
    private:
        int x;
        int y;
        int ids;
    public:
        Tuyo(int id, int start, int height){
            y = height;
            x = start;
            ids = id;
            NF_CreateSprite(1, id, 4, 4, x, y);
        }
        void Check(){
            x -= 3;
            NF_MoveSprite(1, ids, x, y);
            if(x <= 0){
                x = 256;
            }
        }
        void End(){
            NF_DeleteSprite(1, ids);
        }
        void setPoint(int n){
            poins[n] = x;
        }
};
#endif