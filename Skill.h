#pragma once
#include<iostream>
#include<string>
using namespace std;
class Skill {
private:
	string skill[11];
	int flag[11];
	int damage[11];
	int consumption[11];
public:
	Skill();
	void setSkillLearned(int i);
	bool iflearnt(int i);
	void LearnSkill(int level);
	string getSkillName(int i);
	int UseSkill(int name, int force);
	int getSkilldamage(int i);
	int getSkillconsumption(int k);
	void showSkill();
};