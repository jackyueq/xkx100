// fuchen.c 
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("����", ({ "fuchen" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"����һ��������������ϸ������ֻ��Ĩ����Ӭ�Ĺ���
����������ʿ����ĵ��ߣ��ͽ���ʧȥԭ���������ˡ�\n");
		set("value", 300);
		set("material", "leather");
		set("wield_msg",
"$N��ৡ���һ���Ӿ��г��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؾ��С�\n");
	}
	init_whip(15);
	setup();
}

