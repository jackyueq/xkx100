// hongzao.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;


void create()
{
	set_name(RED"����"NOR, ({"hong zao", "hongzao"}));
	set_weight(4000);
	set("long", "һ�Ѻ��Ĵ��档\n");
	set("unit", "��");
	set("value", 0);
	set("fruit_remaining", 18); 
	set("food_supply", 2);   
	set("water_supply", 1);  
	set("eat_msg", "$N����$n������һ�ŵ�������ۡ���һ���³���ˡ�\n"); 
	set("end_msg", "$N��ʣ�µ�$n���˸��ɾ���\n");  
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	setup();
}

