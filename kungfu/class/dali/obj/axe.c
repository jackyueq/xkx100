// axe.c �師

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("�師", ({ "ban fu", "axe", "fu" }));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����صİ師��\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������\n");
	}
	init_axe(25);
	setup();
}
