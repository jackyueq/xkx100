// blade.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit BLADE;

void create()
{
	 set_name(HIW"����"NOR, ({"bao dao", "dao" }) );
	 set_weight(4000);
	 if( clonep() )
		 set_default_object(__FILE__);
	 else {
		 set("unit", "��");
		 set("value", 500);
		 set("material", "iron");
		 set("long", "���ƺ���һ�Ѳ�ͬѰ���ı�����͸��һ��ɱ����\n");
		 set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		 set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	 }
	 init_blade(25);
	 setup();
}
