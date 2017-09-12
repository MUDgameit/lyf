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
	oc << character->getAttackSpeed() << endl;
	oc << character->getAvoidRate() << endl;
	oc << character->getChestName() << endl;
	oc << character->getDefense() << endl;
	oc << character->getExperience() << endl;
	oc << character->getForceRate() << endl;
	oc << character->getHitRate() << endl;
	oc << character->getInterForce() << endl;
	oc << character->getLegName() << endl;
	oc << character->getLevel() << endl;
	oc << character->getLife() << endl;
	oc << character->getNegative_state_rate() << endl;
	oc << character->getShoulderName() << endl;
	oc << character->getStrength() << endl;
	oc << character->getWeaponName();
	oc.close();
	ofstream obag("bag.txt");
	for (int i = 0; i < bag->getNum(); i++) {	
		obag << bag->nameOfEquipment(i);
		if(i+1 < bag->getNum())
			obag << endl;
	}
		obag.close();
	ofstream oskill("SkillName.txt");
	for (int j = 0; j < 11; j++) {
		if (skill->iflearnt(j))
		{
			oskill << j ;
			if (skill->iflearnt(j + 1))
				oskill << endl;
		}
	}
	oskill.close();
	ofstream otask("task1.txt");
	for (int j = 0; j < task->getNowTask(); j++) {
		otask << j ;
		if(j+1 < task->getNowTask())
			otask << endl;
	}
	otask.close();
}