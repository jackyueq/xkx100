// yudi.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�����", ({ "biyu di","yudi","biyudi", "di" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 20000);
		set("material", "wood");
		set("long", "һ�������ƾ͵ĵ��ӣ���ӨӨ�����Ǿ��¡�\n");
		set("wield_msg", "$N����һ��$n���ڴ�������һ����\n");
		set("unwield_msg", "$NЦ��һЦ����$n������䡣\n");
	}
	init_sword(15);
	setup();
}
