// pipa.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(YEL"����"NOR, ({"pi pa", "pipa"}));
	set_weight(4000);
	set("long", "һ���Ƴγε����ˣ���������ˮ��\n");
	set("unit", "��");
	set("life", 5);
	set("value", 0);
	set("fruit_remaining", 4); 
	set("food_supply", 12);   
	set("water_supply", 24);  
	set("eat_msg", "$N����$n������Ƥ������һ�ŵ�������ۡ���һ���³��ˡ�\n"); 
	set("end_msg", "$N��ʣ�µ�$n���˸��ɾ���\n");  
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	set("gifts", ([
		"spi" : 1,
		"int" : 1,
		"con" : 1,
		"per" : 1,
	]));
	setup();
}

