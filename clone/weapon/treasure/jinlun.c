// jinlun.c ����
// Last Modified by winder on Sep. 7 2001

#include <ansi.h>;
#include <weapon.h>;
inherit HAMMER;
inherit F_UNIQUE;

void create()
{
	set_name( HIY "����" NOR,({ "jin lun" ,"lun" ,"jinlun" }));
	set_weight(100000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",HIY"����һ����������ķ��֡�\n"NOR);
		set("value", 10000);
		set("material", "gold");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg","$N�����е�$n�Ż����䡣\n");
	}
	init_hammer(150);
	setup();
}
