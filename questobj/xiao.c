// xiao.c
#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
	set_name(HIG"������"NOR, ({ "lvyv xiao", "xiao"}));
	set_weight(4000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����������ɵĶ��\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ���ӻ����ͳ�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���ػ��\n");
	}
	setup();
}

