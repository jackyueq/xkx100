// Last Modified by Winder on May. 25 2001
// fangbianchan.c

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("�����", ({ "fangbianchan","fangbian", "chan" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 5);
		set("material", "wood");
		set("long", "һ���ǳ��ִ��ʵ�ķ������\n");
		set("wield_msg", "$N����һ��$n�������е���������\n");
		set("unwield_msg", "$N����һ������$n�Ż����\n");
	}
	init_staff(35);
	setup();
}
