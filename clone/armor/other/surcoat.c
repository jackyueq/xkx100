// surcoat.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit SURCOAT;

void create()
{
	set_name("����", ({"surcoat"}));
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

