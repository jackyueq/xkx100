// whip.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("Ƥ��", ({"whip"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ��������Ƥ�ޣ�����մ����Ѫ��\n");
		set("unit", "��");
		set("value", 500);
	}
	init_whip(10);
	setup();
}

