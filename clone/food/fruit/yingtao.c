// yingtao.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(HIR"ӣ��"NOR, ({"ying tao", "yingtao", "cherry"}));
	set_weight(100);
	set("long", "һ���ʺ��ӣ�ң��������Ρ�\n");
	set("unit", "��");
//	set("value", 20);
	set("life", 4);
	set("fruit_remaining", 5); 
	set("food_supply", 10);   
	set("water_supply", 10);  
	set("eat_msg", "$N����$n�������ﶪ��һ��\n"); 
	set("end_msg", "$N�Թ������һ��$n��\n");  
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("gifts", ([
		"spi" : 1,
	]));
	setup();
}

