// kuojian.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("����", ({ "wide sword", "sword", "jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ɽ���ӳ��õĵ�������\n");
		set("value", 300);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(30);
	setup();
}
