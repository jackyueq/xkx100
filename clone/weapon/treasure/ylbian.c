// ylbian.c ������

#include <ansi.h>
#include <weapon.h>
inherit WHIP;
inherit F_UNIQUE;

void create()
{
	set_name(HIC "������" NOR, ({ "yunlong bian", "bian" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "������ػ��ܶ����½��ϵ����������\n");
		set("value", 100);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_whip(150);
	setup();
}
