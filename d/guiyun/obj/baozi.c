// Obj: /d/guiyun/obj/baozi.c
// Last Modified by winder on Jul. 9 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("С����", ({"baozi"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������˵İ��ӡ�\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 30);
	}
}
