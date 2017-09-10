#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include <string>
#include "Article.h"
using namespace std;

class Equipment :public Article{
public:
    Equipment(string my_name);
    string getName();
    int getCategory();
    double getDefense();
    double getAvoidRate();
    double getLife();
    void setEquipment(bool status);
	void showInformation();
private:
    string name; // 名称
    int category; // 护肩为1，胸甲为2，护腿为3
    double defense; // 防御
    double avoid_rate; // 回避率
    double life; // 生命
    bool has_equip; // 是否装备
};



#endif // EQUIPMENT_H_INCLUDED
