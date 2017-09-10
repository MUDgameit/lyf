#include"Skill.h"
#include<iostream>
#include<Windows.h>
void Skill::LearnSkill(string name) {
	int i;
	//查询技能情况之后判断学习情况
	for (i = 0; i < 10; i ++)
	{
		if (name == skill[i])
		{
			if (!flag[i])
			{
				flag[i] = 1;
				cout << "成功学习此技能" << endl;
			}
			else
			{
				cout << "该技能已学习" << endl;
			}
		}
	}
	if (i == 10)
	{
		cout << "所选技能不存在" << endl;
	}
}

int Skill::UseSkill(int name, int force) {
	int i=0;
	for (i = 0; i < 11; i++)
	{
		if (name==i)
		{
			if (flag[i] == 1)
			{
				if (force >= consumption[i])
				{
					force -= consumption[i];
					return force;

				}
				else
				{
					cout << "内力不足！" << endl;
					return force;
				}
			}
			if(flag[i] == 0)
			{
				cout << "该技能尚未学习！" << endl;
				return force;
			}
		}
		else
		{
			cout << "不存在该技能！" << endl;
			return force;
		}
	}
	return force;
}
void Skill::showSkill() {
	int j;
	//查询技能情况
	for (j = 0; j < 11; j++)
	{
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 14);
		if (flag[j]==1)//如果学会了该技能，就显示该技能
			cout << j << "  " << skill[j] << " ";

	}
	cout << endl;
}
Skill::Skill() {//一共11个技能，普攻代号是0，数组下标就是技能代号
	skill[0]="普通攻击", damage[0] = 30, consumption[0] = 0;
	skill[1] = "崩山击", damage[0] = 50, consumption[0] = 10;
	skill[2] = "十字斩", damage[1] = 60, consumption[1] = 10;
	skill[3] = "幻影剑舞", damage[2] = 65, consumption[2] = 20;
	skill[4] = "雷鸣千军破", damage[3] = 70, consumption[3] = 30;
	skill[5] = "暗影之矛", damage[4] = 80, consumption[4] = 30;
	skill[6] = "霹雳旋踢", damage[5] = 90, consumption[5] = 30;
	skill[7] = "旋风腿", damage[6] = 90, consumption[6] = 20;
	skill[8] = "夺命雷霆枪", damage[7] = 100, consumption[7] = 30;
	skill[9] = "破灭斩", damage[8] = 130, consumption[8] = 50;
	skill[10] = "横扫八荒", damage[9] = 200, consumption[9] = 80;
	flag[0] = 1;//初始人物会普攻
	for (int i = 1; i < 11; i++)
	{
		flag[i] = 0;//初始没有学会技能
	}

}
int Skill::getSkilldamage(int i) {//返回伤害值
	return damage[i];
}
int Skill::getSkillconsumption(int k) {//返回消耗法力的值
	return consumption[k];
}
void Skill::setSkillLearned(int i) {//读文件的时候让已经学会的技能设置学会状态
	flag[i] = 1;
}
bool Skill::iflearnt(int i) {//判断是否学会该技能
	if (flag[i] == 1)
		return true;
	else
		return false;
}
