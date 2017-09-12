#include"SkyMountain.h"
SkyMountain::SkyMountain(string layername, task* point, Character *gamer) :layer(layername), point(point), ifFinishTask(false)
{
    system("cls");
    changelayerintroduction("行至天山脚下。");
    changetreasure("武器");
    smalllayerintroduction[0] = "二人/一人行至天山脚下。\n我：（天山老怪竟居住在如此寒冷的地方啊….）\n我刚要取出随身携带的干粮充饥，就看到一张飞镖袭来——\n陶云（天山老怪二徒弟）：来者何人？\n我轻松闪过：我便是雪山派A，前来寻找天山老怪费渡，为我师父报仇！\n陶云：我师父已经多年未曾离开天山，怎可能同你师父有仇恨？要想见他，先过了我这关吧！\n";
    smalllayerintroduction[1] = "陶云：我竟输在你这无名小辈手下！\n我：说吧，费渡在哪里。\n陶云（擦掉嘴角的血迹，及其不甘的看了我一眼）：我师父就在天山山峰上，若是有命上去你就自己寻他吧！\n我继续沿着天山上行。风似乎吹的更猛烈了，天色更加阴暗。\n不多时，我看见了一红衣男子正坐在一堆篝火旁，火上烤着一只兔子，兔肉的香气弥漫在空气中。\n孙泽翼（天山老怪大徒弟）：嗯？你是谁？怎得能上天山来？\n我：我便是雪山派弟子，天山老怪费渡近日杀害了我师父，我来天山正是来寻费渡为我师父报仇！\n孙泽翼：若你是寻常人士来上天山，我必代替师父招待你一番。但你无凭无据就说我师父杀了人，这可不能放过了！\n";
    smalllayerintroduction[2] = "我：我手中有你师父的黄玉吊坠，即使不说他杀了人，也能说明他和我师父的死有关系！\n孙泽翼：可是我师父的吊坠早已丢失了啊！罢了，你自己上山去询问我师父吧！\n我行至山峰，看见一汪湖水正泛着七彩光芒。正待去水旁简单梳洗一番，却听到水边一女子声音：师父，我们今天吃什么菜啊！\n我：天山老怪费渡！速速出来给我一个解释！\n璃音（天山老怪小徒弟）：竟然如此不尊重我师父！快快下山去，不要误了我给师父做饭！\n";
    smalllayerintroduction[3] = "天山老怪：你是何人？竟然打伤我爱徒！看来你今天是不想离开天山了！\n";
	smalllayerintroduction[4] = "天山老怪被打败后——\n我：我便是雪山派我，前几日我师父被歹人谋害，在他房间发现了你的玉坠，我今天来天山便是来找你要个说法。\n费渡：后生可畏，后生可畏。不过那玉坠确实在我退隐时丢失，老夫也不知这玉坠究竟如何落到那歹人手中。况且老夫已经多年未下天山，平日全靠我这几个徒弟下山采买和探听消息。日前听闻魔教重又兴起，谋害于你师父也是有极大可能。武当山聚集了众多武林人士比武来选出讨伐魔教的首领，你可去那里探听相关消息。\n我：多谢前辈。\n天山老怪：老夫有一冒昧请求，那玉坠原是故人相赠，多年前丢失而今失而复得，能否将其归还于老夫？老夫可在你需要之时祝你一臂之力。\n我：既然前辈与我师父的死因没有关系，那这玉坠物归原主也无妨。在此谢过前辈了。\n天山老怪：（轻轻摸着杏果玉坠）闻舟…..\n";

    monstername[0] = "陶云";
    monstername[1] = "孙泽翼";
    monstername[2] = "璃音";
    monstername[3] = "天山老怪";

    smalllayer[0] = "天山山脚";
    smalllayer[1] = "天山山麓";
    smalllayer[2] = "天山天池";
    smalllayer[3] = "天山山顶";
    operate(gamer);
}
SkyMountain::~SkyMountain()
{

}
void SkyMountain::judgeTask()
{
    if (point->getNowTask() > 4)
    {
        ifFinishTask = true;
    }
}
void SkyMountain::move(int i)
{
    system("cls");
    cout << smalllayer[i] << endl;
    movestep(i);
    gettreasure();
}
void SkyMountain::operate(Character * gamer)
{
    int mapFlag = 1;
    while (true)
    {
        system("cls");
        int taskState = point->getNowTask();
        switch (taskState)
        {
        case 1:
            cout << "1.天山山脚\t0.返回" << endl;
            mapFlag =1;
            break;
        case 2:
            cout << "1.天山山脚\t2.天山山麓\t0.返回" << endl;
            mapFlag =2;
            break;
        case 3:
            cout << "1.天山山脚\t2.天山山麓\t3.天山天池\t0.返回" << endl;
            mapFlag =3;
            break;
        default :
            cout << "1.天山山脚\t2.天山山麓\t3.天山天池\t4.天山山顶\t0.返回" << endl;
            mapFlag =4;
            break;
        }
        cout << "请输入你选择的地点：";
        int choice = 1;
        try
        {
            if (cin >> choice)
            {
                if(choice > mapFlag || choice < 0)
                    break;
                else
                {
                    switch (choice)
                    {
                    case 1:
                    {
                        if (taskState==1)
                        {
                            cout << smalllayerintroduction[0] << endl;
                            Monster monster = Monster("陶云", "普通攻击","碎骨匕首");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,1);

                            break;
                        }
                        else
                        {
                            Monster monster = Monster("陶云", "普通攻击","碧水剑");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,1);
                            break;
                        }
                    }
                    case 2:
                    {
                        if (taskState ==2)
                        {
                            cout << smalllayerintroduction[1] << endl;
                            Monster monster = Monster("孙泽翼", "普通攻击","铁弓");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,2);

                            break;
                        }
                        else
                        {
                            Monster monster = Monster("孙泽翼", "普通攻击","虎皮绑腿");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,2);
                            break;
                        }
                    }
                    case 3:
                    {
                        if (taskState==3)
                        {
                            cout << smalllayerintroduction[2] << endl;
                            Monster monster = Monster("璃音", "普通攻击","绫罗披肩");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,3);

                            break;
                        }
                        else
                        {
                            Monster monster = Monster("璃音", "普通攻击","铁弩");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,3);
                            break;
                        }
                    }
                    case 4:
                    {
                        if (taskState ==4)
                        {
                            cout << smalllayerintroduction[3];
                            Monster monster = Monster("天山老怪", "普通攻击","玄铁爪");
							
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,4);
							cout << smalllayerintroduction[4];
                            break;
                        }
                        else
                        {
                            Monster monster = Monster("天山老怪", "普通攻击","蟒皮长袍");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,4);
                            break;
                        }
                    }
                    case 0:
                    {
                        break;
                    }
                    default:
                        throw Error("输入不符合规范，请输入数字1-4");
                    }
                }
            }
            else
            {
                throw Error("输入不符合规范，请输入数字1-4");
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
        }
        if (choice == 0)
        {
            break;
        }
    }
}
