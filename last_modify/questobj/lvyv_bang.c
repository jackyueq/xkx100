// bamboo_stick.c

#include <ansi.h>;
#include <weapon.h>;
inherit STICK;

void create()
{
	set_name(HIG"�����"NOR, ({"lvyv bang", "zhu", "stick"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ŵ������������\n");
		set("value", 0);
		set("material", "bamboo");
		set("wield_msg", "$N���һ�����������$Nץ�����С�\n");
		set("unwield_msg", "$N�����е�$n������С�\n");
	}
	setup();
}	
