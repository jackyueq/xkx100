// /d/yixing/task/goods/silk.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"���"NOR, ({ "silk" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һƥ�������俼���ĳ�С�\n");
		set("unit", "ƥ");
		set("value", 1000);
		set("material", "silk");
	}
	setup();
}
