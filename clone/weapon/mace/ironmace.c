//ironmace.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
#include <ansi.h>
inherit MACE;

void create()
{
	set_name("����", ({"iron mace", "mace", "ironmace"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "iron");
		set("long", "һ����ͨ����ڱޡ�\n");
		set("wield_msg", "$N����һ��$n�����˸���ʽ��\n");
		set("unwield_msg", "$N��$n������䡣\n");
	}
	
	init_mace(15);
	setup();
}

