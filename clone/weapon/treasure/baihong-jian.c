// baihongjian.c �׺罣
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name("�׺罣", ({ "baihong jian", "sword", "jian" }));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����������ı�����\n");
		set("value", 10000);
		set("material", "steel");
		set("weapon_prop/personality", 8);
		set("wield_msg", "$N��ৡ���һ�����һ������������$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(100);
	setup();
}
