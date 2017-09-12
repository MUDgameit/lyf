#include"fighting.h"
#include<time.h>
#include<stdlib.h>
fighting::fighting(Monster * monster, Character * character, task * taskPoint, int taskNum):monster(monster),character(character)
{
	skill = character->getSkill();
	mylife = character->getLife();
	enemyslife = monster->returnLife();
	blooding = false;
	this->fight(taskPoint,taskNum);
}

bool fighting::judge()//判断一速的函数，先判断人物武器攻击距离如果是远程人物先攻击，否则再判断人物和怪物的相对速度，谁快谁先攻击
{//true返回是人物先行动
	if ((this->character)->getAttackSpeed() == 1)
		return true;
	else if ((this->character)->getAttackSpeed() >(monster)->getAttackSpeed())
		return true;
	else
		return false;
}

int fighting::firstRound()
{
	if (judge())//判断谁先行动，即第一回合是谁的
		return 0;//偶数表示人物回合
	else
		return 1;//奇数表示怪物回合
}

void fighting::fight(task* point, int task)
{
	int i;
	round = firstRound();//判断第一回合是谁的
	do {
		if ( round % 2 != 0) {//怪物回合，回合数是奇数或者开局是1就是怪物的回合
			srand(time(NULL));
			if (rand() % 10 + 1>((int)(character->getHitRate() * 10)))//判断是否躲避成功，用人物的躲避率，随机数种子是时间
				cout << "你躲避成功" << endl;
			else {//没有躲避成功
				cout << "你被" << monster->returnName() <<//怪物的名字
					monster->returnSkill() << "攻击,造成" <<//怪物的技能
					monster->fighting() * (100.0 / (character->getDefense()+100) )<< "伤害" << endl;//直接计算伤害，没有附加效果，伤害计算公式如下
				mylife -= monster->fighting() * (100.0 / (character->getDefense() + 100));//人物减去血量
			}

			round++;//回合数目加一
		}
		else if ( round % 2 == 0) {//人物回合，回合数是偶数或者开局是0就是人物的回合
			cout << "请选择技能" << endl;
			this->skill->showSkill();//显示人物已经学会的技能
			int select=0;//初始化变量
			try {
				if (cin >> select)//输入选择的技能序号
				{
					switch (select)
					{
					case 0:break;
					case 1:break;
					case 2:break;
					case 3:break;
					case 4:break;
					case 5:break;
					case 6:break;
					case 7:break;
					case 8:break;
					case 9:break;
					case 10:break;
					default:throw Error("输入不符合规范，请输入数字1-10");
					}
					srand((unsigned int)time(NULL));
					//i = rand() % (10 / ((int)(character->getHitRate() * 10))) + 1;
					if (!(this->skill->iflearnt(select)))
						round--;
					else
					{
						force = this->skill->UseSkill(select, force);//剩余法力的计算，显示使用该技能之后剩余法力
						int hurt1 = this->skill->getSkilldamage(select);//伤害的第一部分，是人物使用技能所造成的伤害
						int hurt2 = 0;
						if (rand() % 10+1>((int)(character->getHitRate() * 10)))//判断是否命中，没有命中的话直接回合数加一
						{
							cout << "你的攻击没有命中！" << endl;
						}
						else
						{
							if (1 == rand() % (int)(this->character->getHitRate() * 100))//判断暴击率
								hurt1 = hurt1 * 2;//如果暴击，第一部分攻击乘以二
												  //力量给攻击加成，是伤害的第二部分
							hurt2 = character->getStrength();
							enemyslife -= hurt1 + hurt2;//怪物减血
							cout << "你的攻击造成了" << hurt1 + hurt2 << "点伤害！" << endl;

							if ((int)this->character->getNegative_state_rate() == 1)//判断是否有冰冻眩晕状态，如果有的话回合数加一，即跳过怪物的那个回合
								round++;
							if (blooding)
								enemyslife -= 10;//判断是否有持续出血状态，持续出血每一回合怪物血量减10
						}
					}
					round++;//回合数加一
				}
			}
			catch (Error &e) {
				// 读到非法字符后，输入流将处于出错状态，
				// 为了继续获取输入，首先要调用 clear 函数
				cin.clear();
				// numeric_limits<streamsize>::max() 返回输入缓冲的大小。
				// ignore 函数在此将把输入流中的数据清空。
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << e.what() << endl;
				system("pause");

				system("cls");
			}

		}
	} while ((mylife > 0) && enemyslife >0);//人物和怪物的血量都大于0的情况下，一直战斗
	if (mylife > 0) {//如果战斗结束后人物血量大于0，就是人物胜利
		cout << "战斗胜利！" << endl;
		point->finishTask(task);
		string fallArticle = monster->fall();
		if (fallArticle != "")//怪物是否掉落物品
		{
			cout << "恭喜你获得了" << fallArticle << endl;//经验升级我没写
			character->getBag()->AddWeapon(fallArticle);

		}
		character->setExperience(character->getExperience() + 20);
	}
	else if (mylife < 0 || mylife == 0)//反之人物输了，游戏结束
		cout << "游戏结束" << endl;
	system("pause");
	system("cls");
	if (character->getExperience() >= 100)
	{
		character->setExperience(character->getExperience() - 100);
		character->getSkill()->LearnSkill(character->getLevel());
		character->levelUp();
		cout << "恭喜升级！你学习到了新技能:" << character->getSkill()->getSkillName(character->getLevel()) << endl;
	}
}
