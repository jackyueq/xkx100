// junzijian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIC "���ӽ�" NOR, ({ "junzi_jian", "jian", "sword" }));
	set("taskobj", 1);
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ڱ���ͨ�ڵĽ����������ý�˿���ż����֣�\n"
			    "ǫǫ���ӣ���������\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N��̾һ������$n����������ʡ�\n");
		set("unwield_msg", "$N��һ�Σ�$n��Ȼ���ʡ�\n");
	}
	setup();
}
