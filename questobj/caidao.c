// caidao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("�˵�", ({ "cai dao", "blade" }));
	set_weight(7000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����λεĲ˵���\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؿ�����\n");
	}
	setup();
}
