// jingua.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("���", ({ "golden hammer", "gua", "hammer" }) );
	set_weight(8500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѳ��صĽ�ϣ��ǻʳ���ʿ��ר��������\n");
		set("value", 1200);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	init_hammer(25);
	setup();
}

