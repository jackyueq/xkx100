// neck.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit NECK;

void create()
{
	set_name("Χ��", ({"neck"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("armor_prop/armor", 1);
	}
	setup();
}

