// zizhuxiao.c ������

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(MAG "������" NOR, ({"zizhu xiao", "xiao"}) );
	set_weight(1000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����������Ƴɣ���Լ�������ࡣ��\n");
		set("value", 600);
		set("unit", "֧");
 		set("wield_msg","$N�������ĵİ�$n�������ϡ�\n");
		set("unwield_msg", "$N���������$n��\n");
	}
	init_sword(3);
	setup();
}
