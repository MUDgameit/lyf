#include <iostream>
#include <fstream>
#include"save.h"
#include"character.h"
#include"Bag.h"
#include"Skill.h"
#include"task.h"
save::save(Character * character, Bag *bag, Skill *skill, task *task) {//存档的时候要存的对象都要传指针过来
	ofstream oname("name.txt");
	oname << character->getName();
	oname.close();
	ofstream oc("character.txt");
	oc << character->getAttackSpeed();
	oc << character->getAvoidRate();
	oc << character->getChestName();
	oc << character->getDefense();
	oc << character->getExperience();
	oc << character->getForceRate();
	oc << character->getHitRate();
	oc << character->getInterForce();
	oc << character->getLegName();
	oc << character->getLevel();
	oc << character->getLife();
	oc << character->getNegative_state_rate();
	oc << character->getShoulderName();
	oc << character->getStrength();
	oc << character->getWeaponName();
	oc.close();
	ofstream obag("bag.txt");
	for (int i = 0; i < bag->getNum(); i++) {
		vector<Article *>::iterator it;
		obag << (*it)->getName();
		it++;
	}
		obag.close();
	ofstream oskill("SkillName.txt");
	for (int j = 0; j < 11; j++) {
		if (skill->iflearnt)
			oskill << j;
	}
	oskill.close();
	ofstream otask("task.txt");
	for (int j = 0; j < task->getNowTask; j++) {
		otask << j;
	}
	otask.close();
}