#pragma once
#include"layer.h"
#include"monster.h"
#include"task.h"
#include"fighting.h"
#include"character.h"
class DemonMountain : public layer {
public:
	DemonMountain(string, task *, Character *);
	~DemonMountain();
	void judgeTask();
	//移动
	void move(int);
	void operate(Character *);
private:
	//小地图
	string smalllayer[6];
	string smalllayerintroduction[8];
	//怪物
	string monstername[6];
	task * point;
	bool ifFinishTask;
};