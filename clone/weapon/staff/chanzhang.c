// chanzhang.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("����", ({"staff", "zhang"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ȣ����漸�������������죮\n");
		set("value", 500);
		set("material", "iron");
		set("wield_msg","$N�ó�һ��$n���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_staff(25);
	setup();
}

