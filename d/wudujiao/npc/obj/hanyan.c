// hanyan.c ���̴�

#include <weapon.h>;
inherit HOOK;

void create()
{
	set_name("���̴�", ({ "han yan", "yan" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "����һֻ���˺ö����ͭ�̴���\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һֻ$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������С�\n");
	}
	init_hook(5);
	setup();
}
