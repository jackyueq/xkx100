// tiespear.c
// Last Modified by winder on May. 25 2001
 
#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("��ǹ", ({"iron spear", "qiang", "spear"}));
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ǹ��ǹ���������⣮\n");
		set("value", 500);
		set("material", "iron");
		set("wield_msg","$N�ó�һ��$n���������У�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_spear(40);
	setup();
}

