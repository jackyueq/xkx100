// zhudao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("����", ({ "zhu dao", "blade" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������������񵶡�\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N�Ӷ����ͳ�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�Żض��\n");
	}
	init_blade(5,0);
	setup();
}
