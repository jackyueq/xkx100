// ��ذ��.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIY"��ذ��"NOR, ({ "jin bishou", "jian", "bishou" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����������ذ�ף�����ȥ���������\n");
		set("value", 10000);
		set("material", "gold");
		set("wield_msg", "$N������Ϣ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�Ż����䡣\n");
	}
	init_sword(37);
	setup();
}
