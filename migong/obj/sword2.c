#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIC"��罣"NOR, ({ "sword", "jian" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������Ƴɵı������������쳣������\n");
		set("value", 500000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(200);
	setup();
}
