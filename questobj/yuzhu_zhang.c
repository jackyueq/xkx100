// bamboo_stick.c

#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name(HIC"������"NOR, ({"yuzhu_zhang", "zhu", "stick"}));
	set_weight(5000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ŵ����������ȡ�\n");
		set("value", 0);
		set("material", "bamboo");
		set("wield_msg", "$N���һ�����������$nץ�����С�\n");
		set("unwield_msg", "$N�����е�$n������С�\n");
	}
	setup();
}	
