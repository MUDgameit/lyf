#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include <string>

using namespace std;

class Weapon {
public:
    Weapon(string my_name);
    string getName();
    double getStrength();
    double getHitRate();
    double getDefense();
    double getAvoidRate();
    double getForceRate();
    double getAttackSpeed();
    int judgeDistance();
    void setEquipment(bool status);
private:
    string name;
    double strength;
    double hit_rate;
    double defense;
    double avoid_rate;
    double force_rate;
    double attack_speed;
    int is_distance;
    bool has_equip;
};


#endif // WEAPON_H_INCLUDED
