#pragma once
#include"layer.h"
#include"monster.h"
#include"task.h"
#include"fighting.h"
#include"character.h"
class DemonShrine : public layer {
public:
	DemonShrine(string, task *, Character *);
	~DemonShrine();
	void judgeTask();
	//移动
	void move(int);
	void operate(Character *);
private:
	//小地图
	string smalllayer[7];
	string smalllayerintroduction[7];
	//怪物
	string monstername[6];
	task * point;
	bool ifFinishTask;
};