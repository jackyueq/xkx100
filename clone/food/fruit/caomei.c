// caomei.c

#include <ansi.h>

inherit ITEM;
inherit F_FRUIT;

void create()
{
	set_name(HIR"��ݮ"NOR, ({"cao mei", "caomei", "stawberry"}));
	set_weight(4000);
	set("long", "һ���ʺ�Ĳ�ݮ���������Ρ�\n");
	set("unit", "��");
	set("life", 3);
	set("value", 0);
	set("fruit_remaining", 8); 
	set("food_supply", 1);   
	set("water_supply", 3);  
	set("eat_msg", "$N����$n�������ﶪ��һ��\n"); 
	set("end_msg", "$N�Թ������һ��$n��\n");  
	set("over_msg", "����ô�ࣿС�ĳ��ƶ�Ƥ��������\n"); 
	setup();
}

