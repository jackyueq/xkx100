// wandouhuang.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>;
void create()
{
	set_name(HIY"�㶹��"NOR, ({"wandou huang", "huang"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 5);
		set("food_supply", 8);
	}
}

