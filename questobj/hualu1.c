// hualu1.c
#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name(HIR"õ�廨¶"NOR, ({ "meigui hualu", "hualu" }));
	set_weight(1500);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һƿõ�廨¶�������ǻ��˲�����Ѫ���Ƴɵġ�\n");
		set("unit", "ƿ");
		set("value", 0);
	}
}

