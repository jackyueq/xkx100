// putao.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(MAG"����"NOR, ({"pu tao", "putao","grape"}));
	set_weight(4000);
	set("long", "һ����Ө�ɰ������ѡ�\n");
	set("unit", "��");
	set("life", 7);
	set("value", 0);
	set("fruit_remaining", 5); //���Գ�10��
	//set("food_supply", 2);   //ÿ�ڼ�2��food
	set("water_supply", 20);  //ÿ�ڿ��Լ�5��water
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n��ժ�˼�������ȥ��\n"); 
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N�������⴮$n��\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("gifts", ([
		"per" : 1,
		"int" : 1,
	]));
	setup();
}

