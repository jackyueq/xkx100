// lemon.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;

void create()
{
	set_name(HIG"����"NOR, ({"ning meng", "ningmeng", "lemon"}));
	set_weight(4000);
	set("long", "һ������ɫ�����ʡ�\n");
	set("unit", "��");
	set("life", 5);
	set("value", 0);
	set("fruit_remaining", 2); 
	set("food_supply", 10);   
	set("water_supply", 40);  
	//ÿ�γԵ�msg,û��Ҳ���Եġ�
	set("eat_msg", "$N����$n������Ƥ������ҧ��һ�ڣ��ۡ��������ˣ���������\n"); 
	//���һ�ڵ�msg��û�����
	set("end_msg", "$N����üͷ���������$n��\n");  
	//�Ա��˵�msg, û����ɣ��������д��ʡ�
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("gifts", ([
		"int" : 1,
		"per" : 1,
		"spi" : 1,
	]));
	setup();
}

