#pragma once
#include"layer.h"
#include"monster.h"
#include"task.h"
#include"fighting.h"
#include"character.h"
class SkyMountain : public layer {
public:
	SkyMountain(string,task *,Character *);
	~SkyMountain();
	void judgeTask();
	//移动
	void move(int);
	void operate(Character *);
private:
	//小地图
	string smalllayer[4];
	string smalllayerintroduction[5];
	//怪物
	string monstername[4];
	task * point;
	bool ifFinishTask;
};