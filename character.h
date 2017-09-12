#pragma once
#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>
#include "equipment.h"
#include "weapon.h"
#include "Skill.h"
#include "Bag.h"
using namespace std;
class Bag;
class Character {
public:
	Character(string my_name,Skill*,Bag*);
	Character();
	int getLevel();
	double getStrength();
	double getHitRate();
	double getAttackSpeed();
	double getDefense();
	double getAvoidRate();
	double getLife();
	double getExperience();
	double getForceRate();
	double getInterForce();
	double getNegative_state_rate();
	void levelUp();
	void setWeapon(Weapon * weapon);
	void setShoulder(Equipment * shoulder);
	void setChest(Equipment * chest);
	void setLeg(Equipment * leg);
	void getOffWeapon();
	void getOffShoulder();
	void getOffChest();
	void getOffLeg();
	string getWeaponName();
	string getShoulderName();
	string getChestName();
	string getLegName();
	string getName();
	void setLevel(int );
	void setStrength(double);
	void setHitRate(double);
	void setAttackSpeed(double);
	void setDefense(double);
	void setAvoidRate(double);
	void setLife(double);
	void setExperience(double);
	void setForceRate(double);
	void setInterForce(double);
	void setNegative_state_rate(double);
	// 力量为1，命中率为2，攻击速度为3，防御力为4，回避率为5，生命值为6，经验值为7，暴击率为8
	void changeAttributes(int name, double point);
	Skill * getSkill();
	Bag * getBag();
private:
	string name;
	int level;
	double strength;
	double hit_rate;
	double attack_speed;
	double defense;
	double avoid_rate;
	double life;
	double experience;
	double force_rate;
	double inter_force;
	double Negative_state_rate;
	Weapon * my_weapon;
	Equipment * my_shoulder;
	Equipment * my_chest;
	Equipment * my_leg;
	Skill * my_skill;
	Bag * my_bag;
};


#endif // CHARACTER_H_INCLUDED
