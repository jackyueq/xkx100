// biyu.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"����"NOR, ({ "bi yu", "yu" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������е���\n");
		set("unit", "��");
		set("value", 80000 );
	}

}
