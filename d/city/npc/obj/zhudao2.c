// zhudao2.c ��
// ���������񵶣�2������

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("��", ({ "zhu dao", "dao", "blade"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
		set("material", "bamboo");
		set("long", 
"����һ���������µ��񵶣�������ϸ�����������������䣬���д�����Ӻ���������ͬ�顣\n");
		set("wield_msg", "$N���һ�������õ�$n���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_blade(1);
	setup();
}
 
