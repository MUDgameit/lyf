#include "weapon.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

Weapon::Weapon(string my_name) {
    name = my_name;

    // 分行读取文件中的数据到数组
    string textline[100];
    int i=0, j=0;
    ifstream fin("weapon.txt");
    while(!fin.eof())
    {
        getline(fin, textline[i], '\n');
        i++;
    }
    fin.close();
    double data[7];
    char str[100];
    const char * split = ",";
    char * p;
    int k = 0;
    for(j = 0; j < i; j++) {
        // 找到与输入名字相同的武器
        if(textline[j].find(name) != string::npos) {
            strcpy(str, textline[j].c_str());
            // 根据逗号分隔字符串
            p = strtok(str, split);
            while(p != NULL && k < 7) {
                // 将字符串转换为double型存入数组
                data[k] = atof(strtok(NULL, split));
                k++;
            }
        }
    }

    // 为武器属性赋值
    strength = data[0];
    hit_rate = data[1];
    attack_speed = data[2];
    defense = data[3];
    avoid_rate = data[4];
    force_rate = data[5];
    is_distance = data[6];
	category = 4;
    has_equip = false;
}

string Weapon::getName() {
    return name;
}

double Weapon::getStrength() {
    return strength;
}

double Weapon::getHitRate() {
    return hit_rate;
}

double Weapon::getDefense() {
    return defense;
}

double Weapon::getAvoidRate() {
    return avoid_rate;
}

double Weapon::getForceRate() {
    return force_rate;
}

double Weapon::getAttackSpeed() {
    return attack_speed;
}

int Weapon::judgeDistance() {
    return is_distance;
}

void Weapon::setEquipment(bool status) {
    has_equip = status;
}

bool Weapon::getHas_Equip()
{
	return has_equip;
}

ostream& operator<<(ostream& out, Weapon *weapon)
{
    //Weapon *weapon = dynamic_cast<Weapon *>(my_article);
    out << "名称：" << weapon->getName() << "\t" << "力量：" << weapon->getStrength() << "\t"
	     << "防御：" << weapon->getDefense() << "\t" << "闪避：" << weapon->getAvoidRate() << "\t"
	     << "暴击：" << weapon->getForceRate() << "\t" << "攻击速度：" << weapon->getAttackSpeed();
    return out;
}

int Weapon::getCategory()
{
	return category;
}
