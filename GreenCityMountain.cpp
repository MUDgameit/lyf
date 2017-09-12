#include"GreenCityMountain.h"
GreenCityMountain::GreenCityMountain(string layername, task* point,Character *gamer) :layer(layername), point(point), ifFinishTask(false)
{
    system("cls");
    changelayerintroduction("");
    changetreasure("武器");

    smalllayerintroduction[0] = "此时，武林人士已经知道我的身份\n少林寺：阿弥陀佛，各位施主还是不要杀我了吧，他虽然是那对夫妇的后人，但是我们不能肯定他也通敌叛国，更何况他也未见过亲生父母。\n龙门镖局：不，我们不能放过他 ，他身上流着逆贼的血，这是什么也改变不了的！\n辉煌门：我觉得父母和孩子没有关系吧…不要动武，真的不要了。\n经过讨论，他们决定，要斩草除根的人去山脚下等待，不同意的人山上继续商讨如何对付魔教。\n龙门镖局：我等正义之士必不会放过你这样流这肮脏血液的人！\n";
    smalllayerintroduction[1] = "败犬派：必让你成为败犬\n";
    smalllayerintroduction[2] = "断袖门：哎，你不从我，我只能选择杀了你了！\n";
    smalllayerintroduction[3] = "青城派：\n若睥睨山选择了1，可拿出文书证明清白\n我：诸位侠客，请容在下说几句（拿出相关证物），这些东西应该足以证明我父母是清白的了吧。\n程澄橙（青城派掌门）：没想到魔教众人竟然如此狠毒，若不是你找出了当年的文书，怕是令尊令堂要一直承受这不白之冤了。如今我们已探得魔教教主藏身地点，你是否愿同我们一起讨伐？\n我：是。我我发誓，定要亲手杀死魔教教主，告慰师父和父母在天之灵！\n获得天蝉护魂长袍（稀有装备）：防御+70  回避+5% 生命值+550\n若睥睨山选择了2，则会被杀死，游戏进入结局二——两代蒙冤。\n";

    monstername[0] = "龙门镖局";
    monstername[1] = "败犬派";
    monstername[2] = "断袖门";

    /*smalllayer[0] = "天山山脚";
    smalllayer[1] = "天山山麓";
    smalllayer[2] = "天山天池";
    smalllayer[3] = "";*/
    operate(gamer);
}
GreenCityMountain::~GreenCityMountain()
{

}
void GreenCityMountain::judgeTask()
{
    if (point->getNowTask() > 10)
    {
        ifFinishTask = true;
    }
}
void GreenCityMountain::move(int i)
{
    system("cls");
    cout << smalllayer[i] << endl;
    movestep(i);
    gettreasure();
}

void GreenCityMountain::operate(Character *gamer)
{
    int mapFlag = 1;
    while (true)
    {
        system("cls");
        int taskState = point->getNowTask();
        switch (taskState)
        {
        case 15:
            cout << "1.龙门镖局\t0.返回" << endl;
            mapFlag = 1;
            break;
        case 16:
            cout << "1.龙门镖局\t2.败犬派\t0.返回" << endl;
            mapFlag = 2;
            break;
        default:
            cout << "1.龙门镖局\t2.败犬派\t3.断袖门\t0.返回" << endl;
            mapFlag = 3;
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
                        if (taskState == 15)
                        {
                            cout << smalllayerintroduction[0] << endl;
                            Monster monster = Monster("龙门镖局", "普通攻击","毒龙之弓");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,15);

                            break;
                        }
                        else
                        {
                            Monster monster = Monster("龙门镖局", "普通攻击", "枯叶刀");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,15);
                            break;
                        }
                    }
                    case 2:
                    {
                        if (taskState ==16)
                        {
                            cout << smalllayerintroduction[1] << endl;
                            Monster monster = Monster("败犬派", "普通攻击", "长刀");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,16);

                            break;
                        }
                        else
                        {
                            Monster monster = Monster("败犬派", "普通攻击", "脊骨剑");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,16);
                            break;
                        }
                    }
                    case 3:
                    {
                        if (taskState ==17)
                        {
                            cout << smalllayerintroduction[2] << endl;
                            Monster monster = Monster("断袖门", "普通攻击", "钉头槌");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,17);

                            break;
                        }
                        else
                        {
                            Monster monster = Monster("断袖门", "普通攻击", "双刃巨剑");
                            system("pause");
                            fighting fight = fighting(&monster, gamer, point,17);
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
