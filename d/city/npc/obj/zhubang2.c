// zhubang2.c ���
// �������������2������

#include <weapon.h>
inherit STICK;

void create()
{
	set_name("���", ({ "zhubang" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���������µ������������ϸ������������������ͬ�顣\n");
		set("value", 2000);
		set("material", "bamboo");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_stick(1);
	setup();
}
 
