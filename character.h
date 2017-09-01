#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>
#include "equipment.h"
#include "weapon.h"

using namespace std;

class Character {
public:
    Character(string my_name);
    double getStrength(); // ��ȡ����ֵ
    double getHitRate(); //��ȡ������
    double getAttackSpeed(); // ��ȡ�����ٶ�
    double getDefense(); // ��ȡ������
    double getAvoidRate(); // ��ȡ�ر���
    double getLife(); // ��ȡ����ֵ
    double getExperience(); // ��ȡ����ֵ
    double getForceRate(); // ��ȡ������
    double getInterForce(); // ��ȡ����ֵ
    void setWeapon(Weapon * weapon); // װ������
    void setShoulder(Equipment * shoulder); // װ������
    void setChest(Equipment * chest); // װ���ؼ�
    void setLeg(Equipment * leg); // װ������
    void getOffWeapon(); // ��������
    void getOffShoulder(); // ���»���
    void getOffChest(); // �����ؼ�
    void getOffLeg(); // ���»���
    string getWeaponName(); // ��ȡ��������
    string getShoulderName(); // ��ȡ��������
    string getChestName(); // ��ȡ�ؼ�����
    string getLegName(); // ��ȡ��������
    // ����Ϊ1��������Ϊ2�������ٶ�Ϊ3��������Ϊ4���ر���Ϊ5������ֵΪ6������ֵΪ7��������Ϊ8
    void changeAttributes(int name, double point);
private:
    string name; // ����
    double strength; // ����
    double hit_rate; // ������
    double attack_speed; // �����ٶ�
    double defense; // ������
    double avoid_rate; // �ر���
    double life; // ����
    double experience; // ����
    double force_rate; // ������
    double inter_force; // ����
    Weapon * my_weapon; // ����
    Equipment * my_shoulder; // ����
    Equipment * my_chest;// �ؼ�
    Equipment * my_leg;// ����
};


#endif // CHARACTER_H_INCLUDED
