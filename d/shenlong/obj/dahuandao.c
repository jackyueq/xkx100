// dahuandao.c  �󻷵�
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(HIW"�󻷵�"NOR, ({ "blade","dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����λεĴ󻷵��������ϻ��м���Բ���������棬�������⡱ֱ�졣\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N�������⡹��һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	init_blade(40);
	setup();
}
