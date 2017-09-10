#pragma once
#include <iostream>
#include "Error.h"
#include <string>
#include <stdlib.h>
#include "character.h"
#include "task.h"
#include<limits>
#include<Windows.h>
using namespace std;

class task;

class operating{
public:
	operating();
	int showStartMenu();
	string getGamerName();
	int showMainMenu(Character &);
	int showMap(task &);
	int showStory(Character &);
};
