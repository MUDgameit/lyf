#include "equipment.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

Equipment::Equipment(string my_name) {
    name = my_name;
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
        if(textline[j].find(name) != string::npos) {
            strcpy(str, textline[j].c_str());
            p = strtok(str, split);
            while(p != NULL && k < 4) {
                data[k] = atof(strtok(NULL, split));
                k++;
            }
        }
    }
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

