// fengdao.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit BLADE;

void create()
{
	 set_name("���µ�", ({"fengyue dao", "dao", "blade"}) );
	 set_weight(6000);
	 if( clonep() )
		 set_default_object(__FILE__);
	 else {
		 set("unit", "��");
		 set("value", 500);
		 set("material", "iron");
		 set("long", "����һ��Ư����˫��Ϸ�µ���\n");
		 set("wield_msg", "$N���һ��$n��৵��������С�\n");
		 set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	 }
	 init_blade(55);
	 setup();
}
