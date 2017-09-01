#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>
#include "equipment.h"
#include "weapon.h"

using namespace std;

class Character {
public:
    Character(string my_name);
    double getStrength(); // 获取力量值
    double getHitRate(); //获取命中率
    double getAttackSpeed(); // 获取攻击速度
    double getDefense(); // 获取防御力
    double getAvoidRate(); // 获取回避率
    double getLife(); // 获取生命值
    double getExperience(); // 获取经验值
    double getForceRate(); // 获取暴击率
    double getInterForce(); // 获取内力值
    void setWeapon(Weapon * weapon); // 装备武器
    void setShoulder(Equipment * shoulder); // 装备护肩
    void setChest(Equipment * chest); // 装备胸甲
    void setLeg(Equipment * leg); // 装备护腿
    void getOffWeapon(); // 脱下武器
    void getOffShoulder(); // 脱下护肩
    void getOffChest(); // 脱下胸甲
    void getOffLeg(); // 脱下护腿
    string getWeaponName(); // 获取武器名称
    string getShoulderName(); // 获取护肩名称
    string getChestName(); // 获取胸甲名称
    string getLegName(); // 获取护腿名称
    // 力量为1，命中率为2，攻击速度为3，防御力为4，回避率为5，生命值为6，经验值为7，暴击率为8
    void changeAttributes(int name, double point);
private:
    string name; // 名称
    double strength; // 力量
    double hit_rate; // 命中率
    double attack_speed; // 攻击速度
    double defense; // 防御力
    double avoid_rate; // 回避率
    double life; // 生命
    double experience; // 经验
    double force_rate; // 暴击率
    double inter_force; // 内力
    Weapon * my_weapon; // 武器
    Equipment * my_shoulder; // 护肩
    Equipment * my_chest;// 胸甲
    Equipment * my_leg;// 护腿
};


#endif // CHARACTER_H_INCLUDED
