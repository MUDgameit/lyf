#include "character.h"
#include "weapon.h"
#include "equipment.h"
#include <iostream>
#include <string>

using namespace std;

// 输入名字初始化人物属性
Character::Character(string my_name) {
    name = my_name;
    strength = 20;
    hit_rate = 0.8;
    attack_speed = 100;
    defense = 50;
    avoid_rate = 0.2;
    life = 200;
    experience = 0;
    force_rate = 0;
    inter_force = 100;
    my_weapon = NULL;
    my_shoulder = NULL;
    my_chest = NULL;
    my_leg = NULL;
}

double Character::getStrength() {
    return strength;
}

double Character::getHitRate() {
    return hit_rate;
}

double Character::getAttackSpeed() {
    return attack_speed;
}

double Character::getDefense() {
    return defense;
}

double Character::getAvoidRate() {
    return avoid_rate;
}

double Character::getLife() {
    return life;
}

double Character::getExperience() {
    return experience;
}

double Character::getForceRate() {
    return force_rate;
}

double Character::getInterForce() {
    return inter_force;
}

void Character::setWeapon(Weapon * weapon) {
    // 判断是否已经装备武器
    if(my_weapon == NULL) {
        my_weapon = weapon;
        strength += weapon->getStrength();
        hit_rate += weapon->getHitRate();
        attack_speed += weapon->getAttackSpeed();
        defense += weapon->getDefense();
        avoid_rate += weapon->getAvoidRate();
        force_rate += weapon->getForceRate();
        weapon->setEquipment(true);
    }
    else {
        cout << "装备失败！" << endl;
    }
}

void Character::setShoulder(Equipment * shoulder) {
    // 判断装备是否为护肩和是否已经装备护肩
    if(shoulder->getCategory() != 1 || my_shoulder != NULL) {
        cout << "装备失败！" << endl;
    }
    else {
        my_shoulder = shoulder;
        defense += shoulder->getDefense();
        avoid_rate += shoulder->getAvoidRate();
        life += shoulder->getLife();
        shoulder->setEquipment(true);
    }
}

void Character::setChest(Equipment * chest) {
    // 判断装备是否为胸甲和是否已经装备胸甲
    if(chest->getCategory() != 2 || my_chest != NULL) {
        cout << "装备失败！" << endl;
    }
    else {
        my_chest = chest;
        defense += chest->getDefense();
        avoid_rate += chest->getAvoidRate();
        life += chest->getLife();
        chest->setEquipment(true);
    }
}

void Character::setLeg(Equipment * leg) {
    // 判断装备是否为护腿和是否装备护腿
    if(leg->getCategory() != 3 || my_leg != NULL) {
        cout << "装备失败！" << endl;
    }
    else {
        my_leg = leg;
        defense += leg->getDefense();
        avoid_rate += leg->getAvoidRate();
        life += leg->getLife();
        leg->setEquipment(true);
    }
}

void Character::getOffWeapon() {
    // 判断是否已经装备武器
    if(my_weapon != NULL) {
        strength -= my_weapon->getStrength();
        hit_rate -= my_weapon->getHitRate();
        attack_speed -= my_weapon->getAttackSpeed();
        defense -= my_weapon->getDefense();
        avoid_rate -= my_weapon->getAvoidRate();
        force_rate -= my_weapon->getForceRate();
        my_weapon->setEquipment(false);
        my_weapon = NULL;
    }
    else {
        cout << "暂未装备任何武器！" << endl;
    }
}

void Character::getOffShoulder() {
    // 判断是否已经装备护肩
    if(my_shoulder == NULL) {
        cout << "暂未装备任何护肩！" << endl;
    }
    else {
        defense -= my_shoulder->getDefense();
        avoid_rate -= my_shoulder->getAvoidRate();
        life -= my_shoulder->getLife();
        my_shoulder->setEquipment(false);
        my_shoulder = NULL;
    }
}

void Character::getOffChest() {
    // 判断是否已经装备胸甲
    if(my_chest == NULL) {
        cout << "暂未装备任何胸甲！" << endl;
    }
    else {
        defense -= my_chest->getDefense();
        avoid_rate -= my_chest->getAvoidRate();
        life -= my_chest->getLife();
        my_chest->setEquipment(false);
        my_chest = NULL;
    }
}

void Character::getOffLeg() {
    // 判断是否已经装备护腿
    if(my_leg == NULL) {
        cout << "暂未装备任何护腿！" << endl;
    }
    else {
        defense -= my_leg->getDefense();
        avoid_rate -= my_leg->getAvoidRate();
        life -= my_leg->getLife();
        my_leg->setEquipment(false);
        my_leg = NULL;
    }
}

string Character::getWeaponName() {
    if(my_weapon == NULL)
        return "无";
    else
        return my_weapon->getName();
}

string Character::getShoulderName() {
    if(my_shoulder == NULL)
        return "无";
    else
        return my_shoulder->getName();
}

string Character::getChestName() {
    if(my_chest == NULL)
        return "无";
    else
        return my_chest->getName();
}

string Character::getLegName() {
    if(my_leg == NULL)
        return "无";
    else
        return my_leg->getName();
}

// 属性加点
void Character::changeAttributes(int name, double point) {
    switch(name) {
        case 1:
        {
            strength += point;
            break;
        }
        case 2:
        {
            hit_rate += point;
            break;
        }
        case 3:
        {
            attack_speed += point;
            break;
        }
        case 4:
        {
            defense += point;
            break;
        }
        case 5:
        {
            avoid_rate += point;
            break;
        }
        case 6:
        {
            life += point;
            break;
        }
        case 7:
        {
            experience += point;
            break;
        }
        case 8:
        {
            force_rate += point;
            break;
        }
        default:
        {
            cout << "该属性不存在！" << endl;
            break;
        }
    }
}


