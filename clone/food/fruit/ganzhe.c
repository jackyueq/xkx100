// ganzhe.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(MAG"����"NOR, ({"gan zhe","ganzhe","sugarcane"}));
	set_weight(4000);
	set("long", "һ���ִ��ֳ��ĸ��ᡣ\n");
	set("unit", "��");
	set("life", 30);
	set("value", 0);
	set("fruit_remaining", 15); //���Գ�15��
	set("water_supply", 10);  //ÿ�ڿ��Լ�10��water
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n���ݺݵ�ҧ��һ��ڣ��������졣\n"); 
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N��ϸ�Ŀ��������$n��\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("gifts", ([
		"per" : 1,
		"con" : 1,
	]));
	setup();
}

