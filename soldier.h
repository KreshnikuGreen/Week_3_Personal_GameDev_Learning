#pragma once

class Soldier{
    private:
        int hp;
        int Max_Hp;
        void Clamp_Health(){
            if(hp < 0){
                hp = 0;
            }
            if(hp > Max_Hp){
                hp = Max_Hp;
            }
        }
 
    public:
        Soldier(): hp(100), Max_Hp(100){}
        Soldier(int Mx_H) : hp(Mx_H), Max_Hp(Mx_H){}

        int Take_Damage(int amount);
        int heal(int amount);
        bool Is_Alive() const;
        int Get_Hp() const;
};

int Random_Int(int min, int max);
