#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("ˮͰ", ({ "shuitong" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "����һ����ԲľȦ�ɵ�ˮͰ����ͨ���յ��ճ���ũ��Ʒ��\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N ����$n���ڼ��ϡ�\n");
		set("unwield_msg", "$N�����ϵ�$n����������\n");
	}
	init_hammer(4);
	setup();
}
