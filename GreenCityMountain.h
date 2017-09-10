#pragma once
#include"layer.h"
#include"monster.h"
#include"task.h"
#include"fighting.h"
#include"character.h"
class GreenCityMountain : public layer {
public:
	GreenCityMountain(string, task *, Character *);
	~GreenCityMountain();
	void judgeTask();
	//移动
	void move(int);
	void operate(Character *);
private:
	//小地图
	string smalllayer[5];
	string smalllayerintroduction[4];
	//怪物
	string monstername[3];
	task * point;
	bool ifFinishTask;
};