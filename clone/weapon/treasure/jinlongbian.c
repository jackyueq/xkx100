// jinlongbian.c ������

#include <ansi.h>
#include <weapon.h>
inherit WHIP;
inherit F_UNIQUE;

void create()
{
	set_name(YEL "������" NOR, ({ "jinlong bian", "bian" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���������̴����������������������ޣ�\n"
		            "���ı��˴��������ɣ�ͨ���������ֱ�ʯ��\n");
		set("value", 20000);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_whip(150);
	setup();
}
