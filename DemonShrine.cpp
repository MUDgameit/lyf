#include"DemonShrine.h"
DemonShrine::DemonShrine(string layername, task* point,Character*gamer) :layer(layername), point(point), ifFinishTask(false) {
	system("cls");
	changelayerintroduction("");
	changetreasure("武器");

	smalllayerintroduction[0] = ".此次清缴魔教行动，众多武林人士参加，连退隐多年的天山老怪也带着他的徒弟再次出山了。\n";
	smalllayerintroduction[1] = "";
	smalllayerintroduction[2] = "";
	smalllayerintroduction[3] = "";
	smalllayerintroduction[4] = ""; 
	smalllayerintroduction[5] = "";
	smalllayerintroduction[6] = "即将杀死最终大BOSS——魔教教主时，教主面具脱落：\n我：师父？！！！\n教主：孽缘啊孽缘。果然是报应吗？（咳血）\n我：不，师父我需要一个解释！\n教主：罢了罢了，我也是马上就要死的人了，告诉你也无妨：我本是魔教左护法，20年前杀死了雪山派掌门并伪装成他的样子，16年前你父母谋反的文书也是我、教主、右护法一同策划的。至于我的死亡么...当然是伪装了，我还是想复兴魔教的。千错万错，大概就是当年心软把你从育婴堂抱了回来吧。没想到啊，你竟然是他们的后人....之前我的确是把你当做亲生孩儿看待，看在你叫我这么多年师父的情分上，我只求死后能留全尸...咳咳.....（魔教教主死）\n我心情复杂，却也依照他的遗言，在同众人商讨后将师父安葬。后来跟随钟宇继续学习武艺，多年后接管武当派，成为新一代武林盟主。游戏进入结局三——大仇得报，终究是人在做，天在看";

	monstername[0] = "魔教长老壹";
	monstername[1] = "魔教长老贰";
	monstername[2] = "魔教长老叁";
	monstername[3] = "魔教长老肆";
	monstername[4] = "魔教长老伍";
	monstername[5] = "魔教教主";
	operate(gamer);
}
DemonShrine::~DemonShrine() {

}
void DemonShrine::judgeTask() {
	if (point->getNowTask() > 10)
	{
		ifFinishTask = true;
	}
}
void DemonShrine::move(int i) {
	system("cls");
	cout << smalllayer[i] << endl;
	movestep(i);
	gettreasure();
}

void DemonShrine::operate(Character *gamer)
{
	int choice = 0;
	while (true)
	{
		system("cls");
		int taskState = point->getNowTask();
		
		cout << smalllayerintroduction[0] << endl;
		Monster monster1("魔教长老壹", "普通攻击","双刃巨剑");
		system("pause");
		fighting fight1 = fighting(&monster1, gamer, point, 11);
		Monster monster2("魔教长老贰", "普通攻击", "千年玄铁兽胸甲");
		fighting fight2 = fighting(&monster2, gamer, point, 11);
		Monster monster3("魔教长老叁", "普通攻击", "魔战钢铁腿甲");
		fighting fight3 = fighting(&monster3, gamer, point, 11);
		Monster monster4("魔教长老肆", "普通攻击", "灵斗者的蚕丝护肩");
		fighting fight4 = fighting(&monster4, gamer, point, 11);
		Monster monster5("魔教长老伍", "普通攻击", "巨兽之魂绑腿");
		fighting fight5 = fighting(&monster5, gamer, point, 11);

		Monster monster6("魔教教主", "普通攻击", "紫榆绑腿");
		cout << smalllayerintroduction[6] << endl;
		cout << "恭喜通过！" << endl;

	}
}
