#include"Bag.h"
#include"Article.h"
void Bag::AddWeapon(string name) {
	bagContent.push_back(new Weapon(name)) ;
}
void Bag::DeleteWeapon(int id) {
	//删除指定位置的元素
	std::vector<Article*>::iterator it = bagContent.begin() + id - 1;
	bagContent.erase(it);
}
void Bag::ShowWeapon( ) {
	
	if (bagContent.size() == 0)
	{
		HANDLE consolehwnd;
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd, 12);
		cout << "背包里没有物品！" << endl;
		SetConsoleTextAttribute(consolehwnd, 9);
		system("pause");
		system("cls");
		
		/*operating_user.showMainMenu(gamer);*/
	}
	else
	{
		int number = 0;
		int i = 0;
		vector<Article *>::iterator it;
		for (it = bagContent.begin(); it != bagContent.end(); it++)
		{
			//每行五个
			for (i = 0; i < 5; i++)
			{
				cout << ++number << "：" << *it << "\t";
				DetialNumber++;
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
						cout << "输入对应序号(输入0则返回主菜单)：" << endl;
						while (true)
						{
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
									}
									else
									{
										bagContent[choice - 1]->showInformation();
									}
								}
							}
							else
							{
								HANDLE consolehwnd;
								consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
								SetConsoleTextAttribute(consolehwnd, 12);
								throw Error("输入不符合规范");
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
Bag::Bag() {
	DetialNumber = 0;
}
int Bag::getNum() {
	return DetialNumber;
}