// yanblade.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("���Ƶ�", ({"yanyun blade", "blade"}));
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ѰײӲӵ����ֺ�����������������ɱ����\n");
		set("value", 1500);
		set("material", "crimsonsteel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������У���ɫ���������ˣ�\n");
		set("unwield_msg","$N�����е�$n�������䣬���¶��һ˿Ц�⡣\n");
		set("weapon_prop/courage", 10);
	}
	init_blade(40);
	setup();
}

