#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name(BLU"������"NOR, ({ "xuantie zhang", "zhang" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����������ĸ��ȡ�\n");
		set("value", 1000000);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�ջر���\n");
	}
	init_staff(200);
	setup();
}
