#include <weapon.h>

inherit AXE;

void create()
{
	set_name("������", ({ "lianhua fu", "axe" , "fu" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "steel");
		set("long", "����һ�ѷ����Ĵ󸫡�\n");
		set("value", 1000000);
//                set("no_put", 1);
//                		set("wield_msg", "$N�ó�һ��$n���������е���������\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	init_axe(200, TWO_HANDED);
	setup();
}
