// bayuban.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit HAMMER;

void create()
{
	 set_name("�����", ({ "baiyu ban", "baiyuban", "yuban", "ban" }) );
	 set_weight(1000);
	 if( clonep() )
		 set_default_object(__FILE__);
	 else {
		 set("unit", "��");
		 set("value", 10000);
		 set("material", "wood");
		 set("long", "һ������ƾ͵İ��ӣ�����������ѹ�֡�\n");
		 set("wield_msg", "$N����һ��$n���������ġ�\n");
		 set("unwield_msg", "$N��$n������䡣\n");
	 }
	 init_hammer(15);
	 setup();
}
