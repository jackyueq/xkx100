#include <ansi.h>
#include <weapon.h>
inherit RING;
void create()
{
        set_name(HIR"������ָ"NOR, ({ "banzi" }) );
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�����ú������ɵİ�ָ��\n");
                	set("value", 1000000);
                             set("rigidity",50);
	        set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
        	set("unwield_msg", "$N�����ϵ�$n���뻳�С�\n");
	}
	init_ring(200);
	setup();
}
