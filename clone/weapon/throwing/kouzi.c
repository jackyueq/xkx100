// kouzi.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("ͭ��", ({"kouzi"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һöСͭ��");
		set("unit", "Щ");
		set("base_unit", "ö");
		set("base_weight", 40);
		set("base_value", 0);
	}
	set_amount(1);
	init_throwing(20);
	setup();
}

