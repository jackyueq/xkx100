// miluozongzi.c ��������

#include <ansi.h>;
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"��������"NOR, ({"miluo zongzi", "zongzi"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һֻ������������ӡ�ÿ�����磬����İ��ն�Ҫ�����������ӣ���ǧ�������س��ס�\n");
		set("unit", "ֻ");
		set("value", 300);
		set("food_remaining", 15);
		set("food_supply", 20);
	}
}
