// mudao.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("ľ��", ({"mu dao","mudao", "dao", "blade"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "wood");
		set("long", "����һľ�Ƶĵ�����������ʱ�õģ�\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������\n");
	}
	init_blade(5);
	setup();
}

