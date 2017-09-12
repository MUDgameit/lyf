#pragma once
#include <iostream>
#include <fstream>
#include "character.h"
#include "Bag.h"
#include "Skill.h"
#include "task.h"
using namespace std;
class Character;
class save {
public:
	save(Character * character,Bag *,Skill *,task *);
};
