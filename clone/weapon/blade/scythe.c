// scythe.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit BLADE;

void create()
{
	 set_name("��������", ({ "scythe","blade","dao","lian dao","lian"}) );
	 set_weight(2000);
	 if( clonep() )
		 set_default_object(__FILE__);
	 else {
		 set("unit", "��");
		 set("value", 300);
		 set("material", "wood");
		 set("long", "����һ��ũ����õĳ���������\n");
		 set("wield_msg", "$N���һ��$n�������У������ϻ����ŵ��ݡ�\n");
		 set("unwield_msg", "$N�����е�$n��������С�\n");
	 }
	 init_blade(10, TWO_HANDED);
	 setup();
}
