// stonehammer.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("ʯ��", ({"stone hammer","stone", "hammer"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ѳ��ص�ʯ����\n");
	}
	init_hammer(25);
	setup();
}

