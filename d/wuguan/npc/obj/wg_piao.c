#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("ư", ({ "piao" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����Ϻ�«�������ɵ�ư����ͨ���յ��ճ���ũ��Ʒ��\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N �ó�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������ϡ�\n");
	}
	init_hammer(4);
	setup();
}
