// yuruyi.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT"������"NOR, ({ "yu ruyi", "ruyi" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����⡣\n");
		set("unit", "��");
		set("value", 200000 );
	}

}

