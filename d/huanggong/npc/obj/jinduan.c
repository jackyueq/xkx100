// jinduan.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("����", ({"jin duan", "jin", "duan"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value", 10000);
	}
	setup();
}
