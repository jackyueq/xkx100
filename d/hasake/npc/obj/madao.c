// madao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("��", ({ "ma dao", "blade", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ĥ��ѩ���������ǹ��������ӵı�־��\n");
		set("value", 1500);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(25);
	setup();
}
