// foshou.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(YEL"����"NOR, ({"fo shou", "foshou" }));
	set_weight(4000);
	set("long", "һ�����Ƶķ��֡�\n");
	set("unit", "��");
	set("life", 7);
	set("value", 0);
	set("fruit_remaining", 2); //���Գ�5��
	set("food_supply", 15);   //ÿ�ڼ�5��food
	set("water_supply", 25);  //ÿ�ڿ��Լ�15��water
	set("eat_msg", "$N����$n�����Ŀ���һ�ڡ�\n");
	set("end_msg", "$N��ϸ�Ŀ��������$n��\n");
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n");
	set("gifts", ([
		"per" : 2,
	]));
	setup();
}
