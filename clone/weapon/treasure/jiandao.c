// jiandao.c �嶾��
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
#include <ansi.h>;
inherit F_UNIQUE;
inherit HOOK;

void create()
{
	set_name("�嶾��", ({ "wudu jian", "jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ű���������һֻ�����������ι�˾綾��\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ���ͳ�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	init_hook(130);
	setup();
}
