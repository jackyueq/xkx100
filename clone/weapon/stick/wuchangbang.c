// wuchangbang.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit STICK;

void create()
{
	set_name("�޳���", ({"wuchang bang", "bang"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�Ѿ��ɵĶ̰���һͷ�ǰ�ɫ��һͷ�Ǻ�ɫ��\n");
		set("unit", "��");
		set("material", "steel");
		set("wield_msg", "$N��Цһ���������Ѷ���һ��$n��\n");
		set("value", 3000);
	}
	init_stick(40);
	setup();
}
