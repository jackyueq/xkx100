// yangmei.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(RED"��÷"NOR, ({"yang mei", "yangmei", "redbayberry"}));
	set_weight(4000);
	set("long", "һ�������޵���÷��\n");
	set("unit", "��");
	set("value", 0);
	set("life", 3);
	set("fruit_remaining", 8); 
	set("food_supply", 1);   
	set("water_supply", 4);  
	set("eat_msg", "$N����$n�������ﶪ��һ�ţ����ۡ����³��ˡ�\n"); 
	set("end_msg", "$N�Թ������һ��$n��ȴ�������е��ᡣ\n");  
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n");
/* 
	set("gifts", ([
		"per" : 1,
		"int" : 1,
		"spi" : 1,
	]));
*/
	setup();
}

