// shizi.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(YEL"����"NOR, ({"shi zi", "shizi","persimmon"}));
	set_weight(4000);
	set("long", "һ���ƳγεĴ����ӡ�\n");
	set("unit", "��");
	set("life", 10);
	set("value", 0);
	set("fruit_remaining", 2); //���Գ�5��
	set("food_supply", 15);   //ÿ�ڼ�5��food
	set("water_supply", 15);  //ÿ�ڿ��Լ�5��water
	set("eat_msg", "$N����$n������ҧ��һ�ڡ�\n");
	set("end_msg", "$N������$n��\n");  
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("core", "����Ƥ");	 //name
	set("core_id", ({"shizi pi", "pi", "peel"}) ); //id
	set("core_unit", "��");	//unit
	set("core_long", "һ������Ƥ��\n"); //long
	set("gifts", ([
		"per" : 1,
	]));
	setup();
}

