// dujili.c 
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("������", ({"poison dart", "dart"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("base_unit", "֦");
		set("long","�������������ޱȣ�����������ɫ������ι�˶�ҩ��\n");
		set("base_weight", 40);
		set("value", 0);
		set("base_value", 5);
	}
	set_amount(20);
	init_throwing(15);
	setup();
}

