// mangguo.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(HIY"â��"NOR, ({"mang guo", "mangguo"}));
	set_weight(4000);
	set("long", "һ�����ĻƳγε�â����\n");
	set("unit", "��");
	set("life", 3);
	set("value", 0);
	set("fruit_remaining", 5); 
	set("food_supply", 15);   
	set("water_supply", 5);  
	set("eat_msg", "$N����$n������Ƥ�����Ŀ���һ�ڡ�\n"); 
	set("end_msg", "$N��ϸ�Ŀ��������$n��\n");  
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("core", "â����");	 //name
	set("core_id", ({"mangguo hu", "hu", "core"}) ); //id
	set("core_unit", "��");	//unit
	set("core_long", "һ��â���ˡ�\n"); //long
	set("gifts", ([
		"con" : 1,
		"per" : 1,
		"spi" : 1,
	]));
	setup();
}

