// juzi.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;

void create()
{
	set_name(YEL"����"NOR, ({"ju zi", "juzi","orange"}));
	set_weight(4000);
	set("long", "һ��ԲԲ�Ľ��ɫ�Ĵ����ӡ�\n");
	set("unit", "��");
	set("life", 20);
	set("value", 0);
	set("fruit_remaining", 3); 
	set("food_supply", 5);   
	set("water_supply", 25);
	set("eat_msg", "$N����$n�����˼����������ȥ��\n");
	set("end_msg", "$N�������һ��$n����ȥ��\n");  
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("core", "����Ƥ");   
	set("core_id", ({"juzi pi", "orange peel", "pi", "peel"}) ); //id
	set("core_unit", "��");   //unit
	set("core_long", "һ������Ƥ��\n"); //long
	set("gifts", ([
		"per" : 1,
		"int" : 1,
	]));

	setup();
}

