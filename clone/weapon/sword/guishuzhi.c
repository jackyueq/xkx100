// Last Modified by winder on May. 25 2001
// guishuzhi.c

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("����֦", ({ "guishuzhi","gui","zhi","jian", "sword" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "wood");
		set("long", "����һ��ϸ���Ĺ���֦��\n");
		set("wield_msg", "$N���һ��ϸ���Ĺ���֦���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
		set("weapon_prop/courage", -4);
	}
	init_sword(6);
	setup();
}
