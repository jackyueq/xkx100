// gou1.c ����

#include <weapon.h>
inherit HOOK;

void create()
{
	set_name("�ֹ�", ({ "gang gou", "gou", "hook" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ר�õĵľ��ָֹ�,�����Ǳ�Ѱ��.\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������С�\n");
	}
	init_hook(100);
	setup();
}
