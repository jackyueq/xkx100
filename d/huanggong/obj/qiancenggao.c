// qiancenggao.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>;
void create()
{
	set_name(HIG"ǧ���"NOR, ({"qianceng gao", "gao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��ǧ�����һ�����һ�������������ɣ����й���������������\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 10);
		set("food_supply", 10);
	}
}

