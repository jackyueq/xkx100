// tielian.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("����", ({"tie lian", "lian", "whip"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ������������������մ����Ѫ��\n");
		set("unit", "��");
		set("value", 500);
	}
	init_whip(25);
	setup();
}

