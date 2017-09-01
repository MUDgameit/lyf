#include "weapon.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

Weapon::Weapon(string my_name) {
    name = my_name;
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
        if(textline[j].find(name) != string::npos) {
            strcpy(str, textline[j].c_str());
            p = strtok(str, split);
            while(p != NULL && k < 7) {
                data[k] = atof(strtok(NULL, split));
                k++;
            }
        }
    }
    strength = data[0];
    hit_rate = data[1];
    attack_speed = data[2];
    defense = data[3];
    avoid_rate = data[4];
    force_rate = data[5];
    is_distance = data[6];
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
