// jinfenggou.c ��ﹳ
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
#include <ansi.h>;
inherit HOOK;
inherit F_UNIQUE;

void create()
{
	set_name(HIY"��ﹳ"NOR, ({ "jinfeng gou", "gou" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ι�˾綾�Ľ𹳣����˺���һֻ��ͷ��\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������С�\n");
	}
	init_hook(130);
	setup();
}
