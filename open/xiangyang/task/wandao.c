// Last Modified by winder on Apr. 25 2001
// wandao.c
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("�ɹ��䵶", ({ "wan dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����λεĸֵ������ɹŹٱ��ĳ���������\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(30);
	setup();
}

