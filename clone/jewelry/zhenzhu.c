// zhenzhu.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT"����"NOR, ({ "zhen zhu", "zhu" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����۴�����顣\n");
		set("unit", "��");
		set("value", 20000 );
	}

}
