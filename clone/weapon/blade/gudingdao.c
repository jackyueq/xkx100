// gudingdao.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit BLADE;

void create()
{
	 set_name("�Ŷ���", ({"guding dao", "dao", "blade", }) );
	 set_weight(10000);
	 if( clonep() )
		 set_default_object(__FILE__);
	 else {
		 set("unit", "��");
		 set("value", 0);
		 set("no_sell", 1);
		 set("no_give", 1);
		 set("no_drop", 1);
		 set("no_put", 1);
		 set("material", "steel");
		 set("long", "һ���⼣�߲��ĳ����������൱�ĳ��ء�\n");
		 set("wield_msg", "$NĨ��Ĩ$n�ϵĻҳ����������\n");
		 set("unequip_msg", "$N��$n�����\n");
	 }
	 init_blade(60);
	 setup();
}
