#include"layer.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
layer::layer(string layername):layername(layername) {
	num = 0;
}

int layer::returnNum()
{
	return num;
}

void layer::showlayer() {
	system("cls");
	cout << layername << endl << introduction << endl;
}

string layer::getlayername() {
	return layername;
}

void layer::changelayername(string name){
	layername = name;
}

string layer::getlayerintroduction(){
	return introduction;
}

void layer::changelayerintroduction(string name){
	introduction = name;
}

void layer::changetreasure(string treasure)
{
	this->treasure = treasure;
}

string layer::gettreasure(){
	//百分之一的概率掉落
	srand((unsigned)time(NULL));
	if ((rand() % 100) + 1 == 1)
	{
		return treasure;
	}
	else
	{
		return "";
	}
}

void layer::movestep(int i)
{
	num = i - 1;
}


