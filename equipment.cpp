#include "equipment.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

Equipment::Equipment(string my_name) {
    name = my_name;

    // 分行读取文件中的数据到数组
    string textline[100];
    int i=0, j=0;
    ifstream fin("equipment.txt");
    while(!fin.eof())
    {
        getline(fin, textline[i], '\n');
        i++;
    }
    fin.close();

    double data[4];
    char str[100];
    const char * split = ",";
    char * p;
    int k = 0;
    for(j = 0; j < i; j++) {
        // 找到与输入名字相同的装备
        if(textline[j].find(name) != string::npos) {
            strcpy(str, textline[j].c_str());
            // 根据逗号分隔字符串
            p = strtok(str, split);
            while(p != NULL && k < 4) {
                // 将字符串转换为double型存入数组
                data[k] = atof(strtok(NULL, split));
                k++;
            }
        }
    }

    // 为装备属性赋值
    defense = data[0];
    avoid_rate = data[1];
    life = data[2];
    category = data[3];
    has_equip = false;
}

string Equipment::getName() {
    return name;
}

int Equipment::getCategory() {
    return category;
}

double Equipment::getDefense() {
    return defense;
}

double Equipment::getAvoidRate() {
    return avoid_rate;
}

double Equipment::getLife() {
    return life;
}

void Equipment::setEquipment(bool status) {
    has_equip = status;
}

bool Equipment::getHas_Equip()
{
	return has_equip;
}

ostream& operator<<(ostream& out, Equipment *equipment)
{
    //Equipment *equipment = dynamic_cast<Equipment *>(article);
    out << "名称：" << equipment->getName() << "\t" << "生命：" << equipment->getLife() << "\t"
         << "防御：" << equipment->getDefense() << "\t" << "闪避：" << equipment->getAvoidRate();
    return out;
}
