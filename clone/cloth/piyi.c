// piyi.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("Ƥ��", ({"pi pao", "pao", "cloth"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	setup();
}

