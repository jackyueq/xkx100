// Obj: /d/guiyun/obj/mifan.c
// Last Modified by winder on Jul. 9 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���׷�", ({"dami fan", "mifan", "fan"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������Ĵ��׷���\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 40);
	}
}
