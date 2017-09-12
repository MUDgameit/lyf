#pragma once
#include"Weapon.h"
#include"equipment.h"
#include"Article.h"
#include<iostream>
#include<string>
#include"operating.h"
#include"character.h"
#include<vector>
#include<limits>
class Character;
using namespace std;
class Bag {
private:
	vector<Article*> bagContent;
public:
	void DeleteWeapon(int i);
	void AddWeapon(string name);
	void ShowWeapon(Character&);
	string nameOfEquipment(int i);
	void equipEquipment(string name, Character& gamer);
	int getNum();
	Bag();
};
