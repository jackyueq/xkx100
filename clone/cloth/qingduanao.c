// qingduanao.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIC"��а�"NOR, ({"qingduan ao", "ao", "cloth"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 250);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}

