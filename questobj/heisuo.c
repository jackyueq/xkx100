// heisuo.c  �����

#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name(BLK"����"NOR, ({ "heisuo", "bian" }));
	set_weight(500);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ͨ������޹⣬�趯֮ʱ�Ʋ������Ӱ�ӡ�\n");
		set("value", 0);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	setup();
}
