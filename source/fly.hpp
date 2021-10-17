#ifndef FLY_HPP
#define FLY_HPP
class Fly{
    private:
        int x = 112;
        int y = 50;
        double speed = 0.5;
        int acc_y = -15;
    public:
        double t = 0;
        Fly(){
            NF_CreateSprite(1, 12, 2, 2, x, y);
        };
        void Check(){
            t = t/60;
            y += acc_y*speed;
            acc_y += 1;
            if(KEY_A & keysDown()){
                acc_y = -10;
            }
            if(y >= ground_y){
                NF_Error(1, "salope", 3);
            }
            NF_MoveSprite(1, 12, x, y);
        };
};
class Tuyo{
    private:
        int x;
        int y;
        int ids;
    public:
        Tuyo(int side, int id){
            y = side*192;
            x = 256;
            ids = id;
            NF_CreateSprite(1, id, 4, 4, x, y);
        }
        void Check(){
            x -= 3;
            NF_MoveSprite(1, ids, x, y);
        }
};
#endif