// mandao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("����", ({ "man dao", "dao", "blade" }));
	set_weight(7000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����λε����������ƹ�������������ĳ���������\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	setup();
}
