// Obj: /d/guiyun/obj/rice.c
// Last Modified by winder on Jul. 9 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�׷�", ({"mi fan", "mifan", "rice"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������˵��׷���\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 40);
	}
}
