#include"DemonMountain.h"
DemonMountain::DemonMountain(string layername, task* point, Character *gamer) :layer(layername), point(point), ifFinishTask(false) {
	system("cls");
	changelayerintroduction("");
	changetreasure("武器");

	smalllayerintroduction[0] = "我到了睥睨山，正看见魔教教众合力重建房屋。他们见一外来人物，又身着白道衣服，二话不说就开始同我战斗。\n";
	smalllayerintroduction[1] = "魔教护法叁：快，快去禀报教主\n";
	smalllayerintroduction[2] = "教主出现\n我：是你当年害我父母，如今又杀我师父吗？\n教主不答，攻击更加猛烈\n";
	smalllayerintroduction[3] = "重伤教主，教主带伤逃走\n";
	smalllayerintroduction[4] = "从柴房中，发现了被捆住的清娴——\n我：清娴，你没事吧。\n清娴：没事，他们抓了我还是为了逼你过来。他们好像认为你对他们的威胁很大，可能还会对你下手，你一定要多加小心。\n我：好。\n";
	smalllayerintroduction[5] = "***选择：是否去教主卧室寻找线索（可能会遇到危险！）？\n1：是\t2：放弃寻找线索。\n";
	smalllayerintroduction[6] = "我们应该去找找当年的线索。或许在教主的卧室里。\n来到教主的卧室里开始翻找。\n我：（拿出一封信）这….莫不是当年伪造的通信文书？\n继续翻找，在信封附近找到了伪造的各种图章。\n我：他们…竟然如此狠毒！这分明是要陷我父母于不忠不义！\n我：（抚摸着笛子）师父…都怪我，竟然没有发现您最爱的笛子都被魔教拿走了…您放心，我一定会抓到杀害您的歹人，用他的血去祭奠您！\n在房间中又找到了一些往来通信，足以证明父母的清白。带着文书返回武当山，却被告知钟宇已经前往青城山。去青城山寻找钟宇。\n教主房间内找到熊骨长枪（稀有装备）： 力量+40  暴击率+2%   命中率-1%   技能攻击力+10%\n";
	smalllayerintroduction[7] = "直接返回武当山，却被告知钟宇已经前往青城山。去青城山寻找钟宇。\n";

	monstername[0] = "魔教护法壹";
	monstername[1] = "魔教护法贰";
	monstername[2] = "魔教护法叁";
	monstername[3] = "魔教护法肆";
	monstername[4] = "魔教护法伍";
	monstername[5] = "魔教教主";
	operate(gamer);
}
DemonMountain::~DemonMountain() {

}
void DemonMountain::judgeTask() {
	if (point->getNowTask() > 10)
	{
		ifFinishTask = true;
	}
}
void DemonMountain::move(int i) {
	system("cls");
	cout << smalllayer[i] << endl;
	movestep(i);
	gettreasure();
}

void DemonMountain::operate(Character *gamer)
{
	int choice = 0;
	while (true)
	{
		system("cls");
		int taskState = point->getNowTask();
		try
		{
			cout << smalllayerintroduction[0] << endl;
			Monster monster1("魔教护法壹", "普通攻击","烈火炼金护腿");
			system("pause");
			fighting fight1 = fighting(&monster1, gamer, point,11);
			Monster monster2("魔教护法贰", "普通攻击", "嗜血腿甲");
			fighting fight2 = fighting(&monster2, gamer, point,11);
			Monster monster3("魔教护法叁", "普通攻击", "征战长戟");
			fighting fight3 = fighting(&monster3, gamer, point,11);
			cout << smalllayerintroduction[1] << endl;
			system("pause");
			Monster monster4("魔教护法肆", "普通攻击", "蚕纱长袍");
			fighting fight4 = fighting(&monster4, gamer, point,11);
			Monster monster5("魔教护法伍", "普通攻击", "灵龟雕纹胸甲");
			fighting fight5 = fighting(&monster5, gamer, point,11);
			cout << smalllayerintroduction[2] << endl;
			Monster monster6("魔教教主", "普通攻击", "断骨长枪");
			cout << smalllayerintroduction[3] << endl;
			cout << smalllayerintroduction[4] << endl;
			cout << smalllayerintroduction[5] << endl;
			while(cout <<"请输入你的选择：") {
                if(cin >> choice) {
                    if(choice == 1 || choice == 2) {
                        point->finishTask(12);
                        point->finishTask(13);
                        break;
                    }
                    else
                        cout << "输入不符合规范，请输入数字1-2" << endl;
                }
            }
			if (choice == 1)
			{
				cout << smalllayerintroduction[6] << endl;
			}
			else
			{
				cout << smalllayerintroduction[7] << endl;

			}
			point->finishNowTask(14);
			break;
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

		break;

	}
}
