// hufa-jiasha.c 
// Last Modified by winder on May. 25 2001

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIY"��������"NOR, ({ "hufa jiasha", "jiasha", "cloth" }) );
	set("long","һ�����ӲӵĻ������ġ�");
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
		set("material", "cloth");
		set("armor_prop/armor", 20);
	}
	setup();
}

