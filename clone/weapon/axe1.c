// axe1.c ����

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("�師", ({ "ban fu", "axe", "fu" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����صİ師��\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
  		set("unwield_msg", "$N�����е�$n�������\n");
	}
	init_axe(100);
	setup();
}
