// changmao.c ��ì
// Last Modifyed by Ahda on Jan. 4 2002

#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("��ì", ({ "changmao" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ľͷ����ĳ�ì��\n");
		set("value", 0);
		set("rigidity",50);
		set("material", "bamboo");
		set("wield_msg", "$N����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������\n");
	}
	init_spear(25);
	setup();
}

