// caoxie.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("��Ь", ({ "cao xie", "xie", "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ˫�����˴��Ĳ�Ь��\n");
		set("material", "wood");
		set("unit", "˫");
		set("value", 10);
	}
	setup();
}

