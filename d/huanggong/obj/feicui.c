// feicui.c ��伦

inherit ITEM;
#include <ansi.h>;

void create()
{
	set_name(GRN"��伦"NOR, ({ "stone chicken", "feicui ji", "ji" }));
	set("weight", 5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 80000);
		set("long", "һ����伦��һ��ĸ���񹤼��Ǿ�ϸ��\n");
		set("material", "stone");
	}
	setup();
}
