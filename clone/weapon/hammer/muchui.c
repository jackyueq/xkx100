// Last Modified by Winder on May. 21 2001
// muchui.c ľ��

#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("ľ��", ({ "muchui", "chui" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����úܾ��µĶ̴���\n");
		set("unit", "��");
		set("value", 100);
		set("wield_msg", "$Nץ��һ��$n���������е�������\n");
		set("material", "wood");
	}
	init_hammer(1);
	setup();
}
