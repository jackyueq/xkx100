// huafu.c
// Last Modified by winder on May. 25 2001

#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
	set_name("������", ({"xuanhua fu", "fu", "axe"}));
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���ǰѳ��صĴ󸫣��а˳߶೤�������ޱȡ�\n");
		set("value", 5000);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n�������У���ǰ����һ�����⡣\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	init_axe(60);
	setup();
}

