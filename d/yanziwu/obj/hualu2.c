// hualu2.c
#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name(HIW"����¶"NOR, ({ "hua lu" }));
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һƿ����¶�������ǻ��˲�����Ѫ���Ƴɵġ�\n");
		set("unit", "ƿ");
		set("value", 50);
	}
}

