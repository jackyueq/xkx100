// muzhang.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("ľ��", ({"mu zhang", "zhang", "staff"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "wood");
		set("long", "����һľ�Ƶ�ľ�ȣ�������ʱ�õģ�\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������\n");
	}
	init_staff(15);
	setup();
}

