// zhanlu-jian.c տ¬��
// Last Modified by winder on Sep. 7 2001

#include <ansi.h>;
#include <weapon.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIC"տ¬��"NOR, ({ "zhanlu jian", "sword", "jian" }));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ǵ�������ŷұ����������ڱ���֮տ¬����\n");
		set("value", 100000);
		set("material", "steel");
		set("weapon_prop/personality", 8);
		set("wield_msg", "$N��ৡ���һ�����һ�ں���������$n�����渡��ԾȻ������ʵ��һ���ѵõ������\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(180);
	setup();
}
