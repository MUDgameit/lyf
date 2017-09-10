#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "Bag.h"
#include "character.h"
#include "DemonMountain.h"
#include "DemonShrine.h"
#include "Error.h"
#include "equipment.h"
#include "fighting.h"
#include "GreenCityMountain.h"
#include "layer.h"
#include "monster.h"
#include "operating.h"
#include "Skill.h"
#include "SkyMountain.h"
#include "task.h"
#include "weapon.h"
#include "WuDang.h"

using namespace std;

int main()
{
	operating operating_user;
	//返回值为零则退出游戏
	int startMenuChoice = operating_user.showStartMenu();
	if (startMenuChoice)
	{
		//新的游戏
		if (startMenuChoice == 1)
		{	
			
			//生成人物
			Character amy(operating_user.getGamerName());
			

			//生成背包
			Bag myBag = Bag();
			//生成技能
			Skill mySkill = Skill();
			//生成任务
			task myTask = task();
			//故事
			myTask.finishNowTask(operating_user.showStory(amy));
			system("cls");
			int mainMenuChoice = 0;
			while (mainMenuChoice = operating_user.showMainMenu(amy))
			{
				//进入地图
				if (mainMenuChoice == 1)
				{
					system("cls");
					int choiceMap;
					while (choiceMap = operating_user.showMap(myTask))
					{
						switch (choiceMap)
						{
							case 1:
							{
								SkyMountain map = SkyMountain("天山", &myTask, &amy);
								break;
							}
							case 2:
							{
								WuDang map = WuDang("武当", &myTask, &amy);
								break;
							}
							case 3:
							{
								DemonMountain map = DemonMountain("魔教睥睨山", &myTask,&amy);
								break;
							}
							case 4:
							{
								GreenCityMountain map = GreenCityMountain("青城山", &myTask,&amy);
								break;
							}
							case 5:
							{
								DemonShrine map = DemonShrine("魔教圣地", &myTask,&amy);
								break;
							}
							
							default:break;
						}
						system("cls");
					}
					if (choiceMap == 0)
					{
						system("cls");
					}
				}
				//查看背包
				if (mainMenuChoice == 2)
				{
					myBag.ShowWeapon();
				}
				//查看任务
				if (mainMenuChoice == 3)
				{
					myTask.showTask();
				}
				mainMenuChoice=0;
			}
			return 0;
		}
		//读取存档
		else
		{

		}
	}
	else
	{
		return 0;
	}

	
	return 0;
}
