#include"Bag.h"
#include"Article.h"
#include"Weapon.h"
#include"equipment.h"
#include<iostream>
void Bag::AddWeapon(string name) {
	if (name.find("腿") != string::npos)
		bagContent.push_back(new Equipment(name));
	else
		if (name.find("肩") != string::npos)
			bagContent.push_back(new Equipment(name));
		else
			if (name.find("甲") != string::npos)
				bagContent.push_back(new Equipment(name));
			else
				if (name.find("袍") != string::npos)
					bagContent.push_back(new Equipment(name));
				else
					bagContent.push_back(new Weapon(name));
}
void Bag::DeleteWeapon(int id) {
	//删除指定位置的元素
	std::vector<Article*>::iterator it = bagContent.begin() + id - 1;
	bagContent.erase(it);
}
void Bag::ShowWeapon(Character& gamer) {

	if (bagContent.size() == 0)
	{
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 12);
		cout << "背包里没有物品！" << endl;
		SetConsoleTextAttribute(consolehwnd, 14);
		system("pause");
		system("cls");

		/*operating_user.showMainMenu(gamer);*/
	}
	else
	{
		int number = 0;
		int i = 0;
		vector<Article *>::iterator it;
		for (it = bagContent.begin(); it != bagContent.end();)
		{
			//每行五个
			for (i = 0; i < 5 && it != bagContent.end(); it++)
			{
				cout << ++number << "：" << (*it)->getName() << "\t";
			}
			cout << endl;
		}
		cout << endl;
		int choice = 3;
		int choice1 = 1;
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 14);
		cout << "1.查看装备详情（输入对应序号）\t0.返回" << endl;
		while (choice1)
		{
			cout << "请输入你的选项：";

			try {
				if (cin >> choice1)
				{
					if (choice1 == 1)
					{

						while (true)
						{
							cout << "输入对应序号(输入0则返回主菜单)：" << endl;
							if (cin >> choice)
							{
								if (choice == 0)
								{
									break;
								}
								else
								{
									if (choice > bagContent.size())
									{
										HANDLE consolehwnd;
										consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
										SetConsoleTextAttribute(consolehwnd, 12);
										cout << "不存在该装备！请重新输入：" << endl;
										SetConsoleTextAttribute(consolehwnd, 14);
									}
									else
									{
									    if(Equipment *equipment = dynamic_cast<Equipment *>(bagContent[choice - 1]))
                                            cout << equipment << endl;
                                        else if(Weapon *weapon = dynamic_cast<Weapon *>(bagContent[choice - 1]))
                                            cout << weapon << endl;
										cout << "是否装备，1.装备 0.返回" << endl;
										int choice_ifEquip, equipType;
										cin >> choice_ifEquip;
										if (choice_ifEquip == 1)
										{
											if (bagContent[choice - 1]->getHas_Equip())
												cout << "该装备已经装备了" << endl;
											else
											{
												bagContent[choice - 1]->setEquipment(true);
												equipType = bagContent[choice - 1]->getCategory();
												switch (equipType)
												{
												case 1:gamer.setShoulder(reinterpret_cast<Equipment*>(bagContent[choice - 1])); cout << "装备成功！" << endl; break;
												case 2:gamer.setChest(reinterpret_cast<Equipment*>(bagContent[choice - 1])); cout << "装备成功！" << endl; break;
												case 3:gamer.setLeg(reinterpret_cast<Equipment*>(bagContent[choice - 1])); cout << "装备成功！" << endl; break;
												case 4:gamer.setWeapon(reinterpret_cast<Weapon*>(bagContent[choice - 1])); cout << "装备成功！" << endl; break;
												}
											}
										}
									}
								}
							}
							else
							{
								HANDLE consolehwnd;
								consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
								SetConsoleTextAttribute(consolehwnd, 12);
								throw Error("输入不符合规范");
								SetConsoleTextAttribute(consolehwnd, 14);
							}
						}
					}
					else
					{
						break;
					}
				}
				else
				{
					HANDLE consolehwnd;
					consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(consolehwnd, 12);
					throw Error("输入不符合规范");
					SetConsoleTextAttribute(consolehwnd, 14);
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
			/*	system("pause");
				system("cls");
				operating_user.showMainMenu(gamer);
				this->ShowWeapon(operating_user, gamer);*/
			}
		}
		system("cls");
		/*operating_user.showMainMenu(gamer);
		this->ShowWeapon(operating_user, gamer);*/
	}
}
string Bag::nameOfEquipment(int i)
{
	return bagContent[i]->getName();
}
void Bag::equipEquipment(string name, Character& gamer)
{
	for (int i = 0; i < bagContent.size(); i++)
	{
		int equipType;
		if (bagContent[i]->getName() == name)
		{
			bagContent[i]->setEquipment(true);
			equipType = bagContent[i]->getCategory();
			switch (equipType)
			{
			case 1:gamer.setShoulder(reinterpret_cast<Equipment*>(bagContent[i])); break;
			case 2:gamer.setChest(reinterpret_cast<Equipment*>(bagContent[i])); break;
			case 3:gamer.setLeg(reinterpret_cast<Equipment*>(bagContent[i])); break;
			case 4:gamer.setWeapon(reinterpret_cast<Weapon*>(bagContent[i])); break;
			}
		}
	}
}
Bag::Bag() {

}
int Bag::getNum() {
	return bagContent.size();
}
