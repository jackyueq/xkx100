// longsword.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIW"����"NOR, ({"bao jian", "sword" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���ƺ���һ�Ѳ�ͬѰ���Ľ����пڷ����ޱȡ�\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(25);
	setup();
}
