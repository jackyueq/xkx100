// throwing.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("�ɻ�ʯ", ({"shi"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�ɻ�ʯ��һ��ʮ�ֳ����İ�����\n");
		set("unit", "Щ");
		set("base_unit", "��");
		set("base_weight", 50);
		set("value", 50);
	}
	set_amount(20);
	init_throwing(20);
	setup();
}

