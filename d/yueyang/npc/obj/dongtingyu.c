// dongtingyu.c ��ͥ��

#include <ansi.h>;
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"��ͥ��"NOR, ({"dongting yu", "fish"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�������ʮ����ζ�Ķ�ͥ�㡣\n");
		set("unit", "��");
		set("value", 500);
		set("food_remaining", 10);
		set("food_supply", 20);
	}
}
