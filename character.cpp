#include "character.h"
#include "weapon.h"
#include "equipment.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include<Windows.h>
using namespace std;

Character::Character(string my_name) {
	name = my_name;
	level = 1;
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
	Negative_state_rate = 0;
	HANDLE consolehwnd;
	consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehwnd, 14);
	cout << "创建人物成功！" << endl;
	system("pause");
	system("cls");
}

int Character::getLevel()
{
	return level;
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
double Character::getNegative_state_rate() {
	return Negative_state_rate;
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
void Character::setLevel(int i)
{
	level = i;
}

void Character::setStrength(double i) {
	strength = i;
}

void Character::setHitRate(double i) {
	hit_rate = i;
}

void Character::setAttackSpeed(double i) {
	attack_speed = i;
}

void Character::setDefense(double i) {
	defense = i;
}

void Character::setAvoidRate(double i) {
	avoid_rate = i;
}

void  Character::setLife(double i) {
	life = i;
}
void Character::setNegative_state_rate(double i) {
	Negative_state_rate = i;
}
void Character::setExperience(double i) {
	 experience=i;
}

void Character::setForceRate(double i) {
	 force_rate=i;
}

void Character::setInterForce(double i) {
	 inter_force=i;
}
void Character::setWeapon(Weapon * weapon) {
	if (my_weapon == NULL) {
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
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 12);
		cout << "装备失败！" << endl;
	}
}

void Character::setShoulder(Equipment * shoulder) {
	if (shoulder->getCategory() != 1 || my_shoulder != NULL) {
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 12);
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
	if (chest->getCategory() != 2 || my_chest != NULL) {
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 12);
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
	if (leg->getCategory() != 3 || my_leg != NULL) {
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 12);
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
	if (my_weapon != NULL) {
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
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 12);
		cout << "暂未装备任何武器！" << endl;
	}
}

void Character::getOffShoulder() {
	if (my_shoulder == NULL) {
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 12);
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
	if (my_chest == NULL) {
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 12);
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
	if (my_leg == NULL) {
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 12);
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
	if (my_weapon == NULL)
		return "无";
	else
		return my_weapon->getName();
}

string Character::getShoulderName() {
	if (my_shoulder == NULL)
		return "无";
	else
		return my_shoulder->getName();
}

string Character::getChestName() {
	if (my_chest == NULL)
		return "无";
	else
		return my_chest->getName();
}

string Character::getLegName() {
	if (my_leg == NULL)
		return "无";
	else
		return my_leg->getName();
}
string Character::getName() {
	return name;
}

void Character::changeAttributes(int name, double point) {
	switch (name) {
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


