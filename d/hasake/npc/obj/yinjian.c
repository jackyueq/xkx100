// ��ذ��.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(WHT"��ذ��"NOR, ({ "yin bishou", "jian", "bishou" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���������������ذ�ף�ʮ�ַ�����\n");
		set("value", 5000);
		set("material", "silver");
		set("wield_msg", "$N��ָ��ڣ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�Ż����䡣\n");
	}
	init_sword(35);
	setup();
}
