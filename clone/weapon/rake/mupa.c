// mupa.c 
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit RAKE;

void create()
{
	set_name("ľ��", ({"mu pa", "pa", "rake"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "wood");
		set("long", "����һ��������ľ�ң�������ʱ�õģ�\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
	}
	init_rake(15);
	setup();
}

