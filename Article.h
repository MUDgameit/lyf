#pragma once
#include<string>
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
	virtual void showInformation() = 0;
};