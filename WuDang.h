#pragma once
#include"layer.h"
#include"monster.h"
#include"task.h"
#include"fighting.h"
#include"character.h"
class WuDang : public layer {
public:
	WuDang(string, task *, Character *);
	~WuDang();
	void judgeTask();
	//移动
	void move(int);
	void operate(Character *);
private:
	//小地图
	string smalllayer[6];
	string smalllayerintroduction[10];
	//怪物
	string monstername[6];
	task * point;
	bool ifFinishTask;
};