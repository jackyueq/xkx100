// tieqiao.c

#include <weapon.h>
inherit CLUB;

void create()
{
	set_name("����", ({ "shenlong qiao", "tie qiao", "qiao" }));
	set_weight(17000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ���ڵص����£��þ��ִ��ƣ�ľ���ϵ���һ����ͷ���ŵĹ��ߡ�\n");
		set("value", 5000);
		set("material", "steel");
		set("no_put",1);
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��غ�����\n");
		set("dig_times", 5);
	}
	init_club(15);
	setup();
}

