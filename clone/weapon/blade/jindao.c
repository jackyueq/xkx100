// jindao.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("��", ({"jin dao", "dao"}));
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ѽ��������Բͷ��������������Ƕ�а���\n");
		set("value", 2500);
		set("material", "gold");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������У����������\n");
		set("unwield_msg", "$N�����е�$n�����ɫ���ʡ�\n");
		set("weapon_prop/courage", 15);
	}
	init_blade(50);
	setup();
}

