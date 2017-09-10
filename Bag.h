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
using namespace std;
class Bag {
private:
	vector<Article*> bagContent;
	int DetialNumber;
public:
	void DeleteWeapon(int i);
	void AddWeapon(string name);
	void ShowWeapon();
	int getNum();
	Bag();
};
