#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(HIW"���±���"NOR, ({ "baodao" , "lengyue baodao" , "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ƽ���ˮ�ı�����\n");
		set("value", 1000000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(250);
	setup();
}
