// zhujian2.c ��
// ���������񽣣�2������

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��", ({ "zhu jian", "jian", "sword"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
		set("material", "bamboo");
		set("long", 
"����һ���������µ��񽣣�������ϸ����������������խ�����⴦�ò�����������������ͬ�顣\n");
		set("wield_msg", "$N�ó�һ�������õ�$n���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_sword(1);
	setup();
}
 
