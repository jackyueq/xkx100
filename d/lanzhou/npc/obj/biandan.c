// biandan.c

#include <weapon.h>;
#include <ansi.h>;
inherit STAFF;

void create()
{
	set_name(GRN"�ⵣ"NOR, ({ "bian dan", "dan" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������ıⵣ��\n");
		set("value", 100);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_staff(1);
	setup();
}