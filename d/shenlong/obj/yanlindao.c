// yanlingdao.c  ���ᵶ
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(HIW "���ᵶ" NOR, ({ "blade","dao" }));
	set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long", "����һ�����λε����ᵶ�������ϵĵ�����ϲ��������\n");
		set("value", 500);
                set("material", "steel");
		set("wield_msg", "$N��ᯡ���һ���γ�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
        }
	init_blade(40);
        setup();
}
