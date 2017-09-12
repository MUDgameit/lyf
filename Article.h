#pragma once
#include<string>
#include<iostream>
using namespace std;
class Article {
public:
	virtual string getName() = 0;
	virtual double getStrength() = 0;
	virtual double getHitRate() = 0;
	virtual double getDefense() = 0;
	virtual double getAvoidRate() = 0;
	virtual double getForceRate() = 0;
	virtual double getAttackSpeed() = 0;
	virtual double getLife() = 0;
	virtual void setEquipment(bool status) = 0;
	virtual bool getHas_Equip() = 0;
	virtual int getCategory() = 0;
};
