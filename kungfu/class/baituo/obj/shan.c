// gangjian.c

#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("ֽ��", ({ "zhi shan", "shan" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������������ֽ�ȣ�����д�š������������ĸ��ν����֡�\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N�Ӷ����ͳ�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�Żᶵ�\n");
	}
	init_dagger(100,0);
	setup();
}
