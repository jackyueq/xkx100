// gangzhang
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("����", ({"gang zhang", "zhang", "staff"}));
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 300);
		set("material", "steel");
		set("long", "����һ���Ƶ��ȣ�\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������\n");
	}
	init_staff(35);
	setup();
}

