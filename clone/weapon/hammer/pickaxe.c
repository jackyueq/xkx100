// pickaxe.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit AXE;

void create()
{
	 set_name("��ͷ", ({ "pickaxe", "axe", "chutou", "chu" }) );
	 set_weight(20000);
	 if( clonep() )
		 set_default_object(__FILE__);
	 else {
		 set("unit", "��");
		 set("long", "һ�ѳ��صĳ�ͷ������ȥ�ܽ�ʵ��\n");
		 set("value", 2000);
		 set("wield_msg", "$N�ó�һ��$n��һ��û���ȣ���������Լ����ϡ�\n");
		 set("unwield_msg", "$N�������е�$n�����������ز��˲�����\n");
	 }
	 init_axe(20, TWO_HANDED);
	 setup();
}
