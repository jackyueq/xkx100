#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name(HIY"������"NOR, ({ "whip", "jinlong bian" , "bian" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����������������ʯ�ĳ��ޡ�\n");
		set("value", 1000000);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_whip(200);
	setup();
}
