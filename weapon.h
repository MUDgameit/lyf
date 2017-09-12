#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include <string>
#include <iostream>
#include "Article.h"
using namespace std;

class Weapon : public Article{
public:
    Weapon(string my_name);
    string getName();
	double getLife() { return 0; }
    double getStrength();
    double getHitRate();
    double getDefense();
    double getAvoidRate();
    double getForceRate();
    double getAttackSpeed();
    int judgeDistance(); // 判断是否为远程武器
    void setEquipment(bool status);
	bool getHas_Equip();
	int getCategory();
	friend ostream& operator<<(ostream& out, Weapon *weapon);
private:
    string name; // 名称
    double strength; // 力量
    double hit_rate; // 命中率
    double defense; // 防御力
    double avoid_rate; // 回避率
    double force_rate; // 暴击率
    double attack_speed; // 攻击速度
    int is_distance; // 是否为远程武器
    bool has_equip; // 是否装备
	int category; // 护肩为1，胸甲为2，护腿为3，武器为4
};


#endif // WEAPON_H_INCLUDED
