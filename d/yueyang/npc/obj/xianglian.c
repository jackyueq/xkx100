// xiangliangeng.c ������

#include <ansi.h>;
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"������"NOR, ({"xianglian geng", "geng"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ���ú��϶�ͥ�������Ӱ��ĸ�����\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 10);
		set("food_supply", 10);
	}
}
