// caichou.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("�ʳ�", ({"whip"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ�������Ĳʳ��������赸�ĵ��ߡ�\n");
		set("unit", "��");
		set("value", 500);
	}
	init_whip(10);
	setup();
}

