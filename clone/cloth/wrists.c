// wrists.c 
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit WRISTS;

void create()
{
	set_name("����", ({ "wrists" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("material", "copper");
		set("value", 100);
		set("armor_prop/armor", 2);
	}
	setup();
}

