// longsword.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("����", ({ "long sword", "sword", "jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ר�õĵľ��ֽ�,�����Ǳ�Ѱ��.\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(100);
	setup();
}
