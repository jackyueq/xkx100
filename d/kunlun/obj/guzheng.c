// guzheng.c ����

#include <ansi.h>;

inherit ITEM;

void create()
{
	set_name(HIG"����"NOR, ({ "gu zheng", "zheng", "qin" }));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
		HIG"����һ������ʮ�ֿ����Ĺ��ݣ������ɫ�����ʼ��á�\n"NOR);
		set("value", 5000);
		set("material", "steel");
	}
}

