// jinqiang.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
	set_name(HIY "���ǹ" NOR, ({ "golden spear","qiang","spear" }));
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 10000);
		set("material", "gold");
		set("long", "��ǹ�Իƽ�ΪͷͭΪ�ˡ�\n");
		set("wield_msg", "$N����һ��$n��˳�ֶ��˸�ǹ����\n");
	}
	init_spear(60);
	setup();
}

