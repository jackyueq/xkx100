// hebi.c �����

#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("�����", ({ "hebi" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", "����һ֧�ʶ�������죬ȴ�Ǿ��������ı�����\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N���һ֧$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
  	init_dagger(40);
	setup();
}