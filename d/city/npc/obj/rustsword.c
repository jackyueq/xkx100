// rustsword.c

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(RED"����"NOR, ({ "rustsword" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���⼣�߰ߵĸֽ��������ƺ�������һЩ��â��\n");
		set("value", 400000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(10);
	setup();
}
