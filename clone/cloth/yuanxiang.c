// yuanxiang.c ����Ь
// Last Modified by winder on May. 25 2001

#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
	set_name(RED"����Ь"NOR, ({"ruanxiang xie", "shoes", "xie"}) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ˫С��������廨Ь��\n");
		set("material", "cloth");
		set("unit", "˫");
		set("value", 2000);
		set("armor_prop/armor", 1 );
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

