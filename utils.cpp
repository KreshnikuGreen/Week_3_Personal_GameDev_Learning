#include "soldier.h"
#include <random>

int Random_Int(int min, int max){
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

int Soldier::Take_Damage(int amount){
    hp -= amount;
    Clamp_Health();
    return hp;
}

int Soldier::heal(int amount){
    hp += amount;
    Clamp_Health();
    return hp;
}

int Soldier::Get_Hp() const{
    return hp;
}

bool Soldier::Is_Alive() const{
    return hp > 0;
}
