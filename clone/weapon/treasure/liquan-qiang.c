// liquan-qiang.c ��Ȫǹ
// Last Modified by winder on Sep. 7 2001

#include <ansi.h>;
#include <weapon.h>;
inherit SPEAR;
inherit F_UNIQUE;

void create()
{
	set_name(HIW"��Ȫǹ"NOR,({"liquan spear", "spear", "qiang"}));
	set_weight(100000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","��������������������������߶����������ս���ɣ�������ǹ��\n");
		set("material", "steel");
		set("no_drop", 1);
		set("value", 100);
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�ջر���\n");
	}
	init_spear(200);
	setup();
}
