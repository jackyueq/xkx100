// ding.c ��ľ����

inherit ITEM;
#include <ansi.h>;
void create()
{
	set_name(YEL"��ľ����"NOR, ({ "shenmu wangding", "ding" }));
	set_weight(500);
	set("taskobj", 1);
	set("count", 50);
	set_max_encumbrance(1000);
	if (clonep())

		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
YEL"����һ��ɫ����Ƶ�ССľ����ľ���������Ǿ�ϸ��ľ�ʼ�����
����ľ��֮������ԼԼ�ķ���"RED"��˿"YEL"�����������ͭǮ���Բ�ף�
ľ���뾱����һ��ϸ�죬�ƺ���Ϊ���ء�\n"NOR);
		set("value", 0);
	}
}

int is_container() { return 1; }

void init()
{
}
