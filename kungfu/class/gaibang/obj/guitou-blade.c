// guitou-blade.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit BLADE;

void create()
{
	 set_name("��ͷ��", ({"guitou dao", "dao", "blade" }) );
	 set_weight(4000);
	 if( clonep() )
		 set_default_object(__FILE__);
	 else {
		 set("unit", "��");
		 set("value", 2500);
		 set("material", "iron");
		 set("long", "����һһ�ѹ�ͷ���������б�������������\n");
		 set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		 set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	 }
	 init_blade(45);
	 setup();
}
