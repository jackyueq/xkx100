#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name( WHT"����"NOR,({ "yin lun" ,"lun" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�Ѵ�����������ӡ�\n");
		set("value", 800000);
		set("material", "wood");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg","$N�����е�$n�Ż����䡣\n");
	}
        init_hammer(200);
	setup();
}
