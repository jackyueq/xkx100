// yuma.c ����

inherit ITEM;
#include <ansi.h>;

void create()
{
	set_name(GRN"�������"NOR, ({ "stone horse", "yu ma", "ma" }));
	set("weight", 5000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("long", "һ������ɵ�����\n");
		set("material", "stone");
	}
	setup();
}
