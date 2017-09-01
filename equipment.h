#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include <string>

using namespace std;

class Equipment {
public:
    Equipment(string my_name);
    string getName();
    int getCategory();
    double getDefense();
    double getAvoidRate();
    double getLife();
    void setEquipment(bool status);
private:
    string name;
    // 护肩为1，胸甲为2，护腿为3
    int category;
    double defense;
    double avoid_rate;
    double life;
    bool has_equip;
};



#endif // EQUIPMENT_H_INCLUDED
