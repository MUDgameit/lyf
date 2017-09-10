#pragma once
#include<string>
#include "operating.h"
using namespace std;
class layer {
public:
	layer(string);
	int returnNum();
	void showlayer();
	string getlayername();
	void changelayername(string name);
	string getlayerintroduction();
	void changelayerintroduction(string name);
	void changetreasure(string);
	//Ëæ»ú»ñµÃ±¦²Ø
	string gettreasure();
	void movestep(int);
private:
	int num;
	string layername;
	string introduction;
	string treasure;
};
