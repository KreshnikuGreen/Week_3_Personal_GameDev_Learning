#include "soldier.h"
#include <limits>
#include <memory>
#include <iostream>



int main(){
    int count;
    int choice;
    int index;
    bool Play_State = true;

    std::cout << "How many soldiers would you like in the squad?\n";
    std::cin >> count;

    std::unique_ptr<Soldier[]> s = std::make_unique<Soldier[]>(count);

    while(Play_State){
        std::cout << "===== Menu =====\n1. Damage Random\n2. Heal\n3. Check Status\n4. Exit\n";
        
        std::cin >> choice;

        if(std::cin.fail() || choice < 1 || choice > 4){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Input.\n";
            continue;
        }

        switch(choice){
            case 1:
                index = Random_Int(0, count - 1);
                s[index].Take_Damage(50);
                break;
            case 2:
                for(int i = 0; i < count; i++){
                    if(s[i].Get_Hp() < s[i].Get_Hp()){
                        s[i].heal(50);
                    }
                }
                break;
            case 3:{
                        int Dead_Count = 0;
                        for(int i = 0; i < count; i++){
                            std::cout << "Soldier: " << i << " HP: " << s[i].Get_Hp() << " Alive: " << s[i].Is_Alive() << "\n";
                            if(s[i].Is_Alive() == false){
                                Dead_Count += 1;
                            }
                            if(Dead_Count == count){
                                std::cout << "SQUAD WIPED\n";
                                return 0;
                            }
                        }
                   }
                break;
            case 4:
                return 0;
                break;
            default:
                return 0;
                break;
        }
    }

    return 0;
}
