// ironaxe.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit AXE;

void create()
{
	 set_name("����", ({ "tiefu", "axe", "fu", "tie fu"}) );
	 set_weight(8000);
	 if( clonep() )
		 set_default_object(__FILE__);
	 else {
		 set("unit", "��");
		 set("long", "����һ�������õ����������������ǳ�˳�֡�\n");
		 set("value", 1000);
		 set("wield_msg", "$N�ó�һ�ѿ����$n���������е���������\n");
		 set("unwield_msg", "$N�������е�$n��\n");
	 }
	 init_axe(20);
	 setup();
}
