// shenlongchi.c ������

#include <weapon.h>
inherit HOOK;

void create()
{
	set_name(HIY"������"NOR, ({ "shenlong ci", "ci" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ����С������ǰ���乳�ı��������������Ķ��ű�����\n");
		set("value", 500);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��غ�����\n");
	}
	init_hook(30);
	setup();
}

