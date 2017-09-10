#include "operating.h"

operating::operating()
{
}

int operating::showStartMenu()
{
	int choice;
	while(cout << "1.开始游戏  2.读取存档  3.退出" << endl << "请输入你的选择：") {
	    try {
            if (cin >> choice)
            {
                switch (choice)
                {
                case 1:return 1;
                case 2:return 2;
                case 3:return 0;
                default:throw Error("输入不符合规范，请输入数字1-3");
                }
            }
            else
            {
                throw Error("输入不符合规范，请输入数字1-3");
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

	return choice;
}

string operating::getGamerName()
{
	system("cls");
	string name;
	cout << "请输入人物名称：";
	try
	{
		cin >> name;
		//长度不超过五，不含空格
		if (name.length() < 6 || name.find(" ") != std::string::npos)
		{
			return name;
		}
		else
		{
			throw Error("输入角色名应中文长度不超过五，英文不超过十，且不含空格。");
		}
	}
	catch (Error &e)
	{
		// 读到非法字符后，输入流将处于出错状态，
		// 为了继续获取输入，首先要调用 clear 函数
		cin.clear();
		// numeric_limits<streamsize>::max() 返回输入缓冲的大小。
		// ignore 函数在此将把输入流中的数据清空。
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << e.what() << endl;
		system("pause");


		system("cls");
		this->getGamerName();
	}
}

int operating::showMainMenu(Character & gamer)
{
	cout << "角色名字：" << gamer.getName() << "\t" << "等级：" << gamer.getLevel() << endl;
	cout << "生命：" << gamer.getLife() << "\t" << "内力：100" << "\t" << "经验：" << gamer.getExperience() << endl;
	cout << "武器：" << gamer.getWeaponName() << "\t" << "头盔：" << gamer.getShoulderName() << "\t" <<
		"铠甲：" << gamer.getChestName() << "\t" << "护腿：" << gamer.getLegName() << endl;
	cout << "力量：" << gamer.getStrength() << "\t" << "防御：" << gamer.getDefense() << "\t" <<
		"命中率：" << gamer.getHitRate() << "\t" << "暴击率：" << gamer.getForceRate() << "\t" <<
		"闪避率：" << gamer.getAvoidRate() << "\t" << "攻速：" << gamer.getAttackSpeed() << endl;
	cout << "1.地图\t2.背包\t3.任务\t4.退出" << endl;
	int choice;
	while(cout << "请输入你的操作（1-4）" << endl) {
	    try {
            if (cin >> choice)
            {
                switch (choice)
                {
                case 1:return 1;
                case 2:return 2;
                case 3:return 3;
                case 4:return 0;
                default:throw Error("输入不符合规范，请输入数字1-4");
                }
            }
            else
            {
                throw Error("输入不符合规范，请输入数字1-4");
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
        cout << "角色名字：" << gamer.getName() << "\t" << "等级：" << gamer.getLevel() << endl;
        cout << "生命：" << gamer.getLife() << "\t" << "内力：100" << "\t" << "经验：" << gamer.getExperience() << endl;
        cout << "武器：" << gamer.getWeaponName() << "\t" << "头盔：" << gamer.getShoulderName() << "\t" <<
            "铠甲：" << gamer.getChestName() << "\t" << "护腿：" << gamer.getLegName() << endl;
        cout << "力量：" << gamer.getStrength() << "\t" << "防御：" << gamer.getDefense() << "\t" <<
            "命中率：" << gamer.getHitRate() << "\t" << "暴击率：" << gamer.getForceRate() << "\t" <<
            "闪避率：" << gamer.getAvoidRate() << "\t" << "攻速：" << gamer.getAttackSpeed() << endl;
        cout << "1.地图\t2.背包\t3.任务\t4.退出" << endl;
	}
	return 0;
}

int operating::showMap(task &myTask)
{
	int numberOfTask = myTask.getNowTask();
	if(numberOfTask < 5)
	{
		cout << "1.天山" << endl;
	}
	else
	{
		if (numberOfTask < 11)
		{
			cout << "1.天山\t2.武当" << endl;
		}
		else
		{
			if (numberOfTask < 15)
			{
				cout << "1.天山\t2.武当\t3.魔教睥睨山" << endl;
			}
			else
			{
				if (numberOfTask < 20)
				{
					cout << "1.天山\t2.武当\t3.魔教睥睨山\t4.青城山" << endl;
				}
				else
				{
					cout << "1.天山\t2.武当\t3.魔教睥睨山\t4.青城山\t5.魔教圣地" << endl;
				}
			}
		}
	}
	cout << "请输入你前往的地图（输入0返回）" << endl;
	int choice;
	try {
		if (cin >> choice)
		{
		    if((numberOfTask < 5 && choice > 1) || (numberOfTask < 11 && choice > 2) || (numberOfTask < 15 && choice > 3) || (numberOfTask < 20 && choice > 4) || choice > 5) {
                cout << "该地图不存在！" << endl;
		    }
		    else {
                switch (choice)
                {
                case 1:return 1;
                case 2:return 2;
                case 3:return 3;
                case 4:return 4;
                case 5:return 5;
                case 0:return 0;
                default:throw Error("输入不符合规范，请输入数字1-5");
                }
		    }
		}
		else
		{
			throw Error("输入不符合规范，请输入数字1-5");
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
	}

	return 0;
}

int operating::showStory(Character &amy)
{
	cout << "这是一个寒冷的冬天。\n";
	cin.get();
	cout << amy.getName() <<
		"刚刚过完了他的16岁生日。从小父母双亡的他是在一个大雪纷飞的冬日被师父报上山来抚养长大的。师父是雪山派的掌门，这些年对他也是悉心教导，在他看来，师父就像父亲一样。和他平日一同习武的还有他的小师妹（张清娴），两人感情也是相当的亲厚。\n一个看似寻常的日子，A刚脱下外套准备就寝的时候，一个黑影突然出现在窗外——\n";
	cin.get();
	cout << amy.getName() << "：谁？！\n";
	cin.get();
	cout <<
		"黑影：别怕，我是你父母的故人，已经寻了你16年了，昨日才从雪山派中寻到了你的消息。\n";

	cin.get();
	cout << amy.getName() <<
		"：口说无凭，你休得乱讲！我自有记忆就未见过父母，是师父将我从小教养，何来父母故人之说！\n";
	cin.get();
	cout <<
		"黑影：你且说，你心口是否有一红色心形胎记？\n";
	cin.get();
	cout << amy.getName() <<
		"：（这么私密的事情怎会有外人得知？或许我真同他有一分渊源…）\n";
	cin.get();
	cout <<
		"黑影：罢了，我今日也不在此久留，待有时间再来望你。（说罢，竟是用轻功离开）。\n";
	cin.get();
	cout << amy.getName() <<
		"：也罢，过几日待到我与师父都出关后再问询师父吧。\n";
	cin.get();

	cout <<
		"十日后......\n" << amy.getName() << "刚出关，正要去寻师父，却听到了师父被人杀害的消息——\n";
	cin.get();
	cout << amy.getName() <<
		"：这....这怎可能....师父...师父竟......（大哭）\n";
	cin.get();
	cout <<
		"待到心情平复些许，" << amy.getName() << "听闻师妹整理师父遗物的时候发现了一枚黄色杏果挂坠，心下有疑，便唤人取来察看。\n";
	cin.get();
	cout << amy.getName() <<
		"：（师父曾讲过，多年前天山老怪行走江湖时，腰间所挂杏果玉坠即为他的身份标识，莫不是...）\n";
	cin.get();
	cout <<
		"待到看见该玉坠，" << amy.getName() << "当即确定天山老怪同师父的死脱不得关系。\n";
	cin.get();
	cout << amy.getName() <<
		"：我便要下山去寻那天山老怪，为师父报仇！\n";
	cin.get();
	cout <<
		"师妹：我同你一起去吧，两人对上那老怪许有更大的把握。\n";
	cin.get();
	cout <<
		"***选择\n" <<
		"1：好，那我们便一同去取那仇人性命，告慰师父在天之灵！\n" <<
		"2：师父刚去世，门派事务还需人打理，你且等着，我必取下那仇人首级！\n";
	cout << "输入你的选择：";
	int choice;
	while (true)
	{
		try 
		{
			if (cin >> choice)
			{
				switch (choice)
				{
				case 1:return 1;
				case 2:return 2;
				default:throw Error("输入不符合规范，请输入数字1-2");
				}
			}
			else
			{
				throw Error("输入不符合规范，请输入数字1-2");
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
		}
	}
	return 0;
}
