// goldjian.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
#include <ansi.h>
inherit MACE;

void create()
{
	set_name(HIY"��װ�"NOR,({"gold mace", "mace", "goldmace", "jinjian"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 20000);
		set("material", "gold");
		set("wield_msg", "$N�����$n���૵���ﵶ���ﵶ���������һ�أ�\n");
		set("unwield_msg", "$N������$n��������һ����������ﵹ�Ȼ�����۷磡\n");
	}
	
	init_mace(95);
	setup();
}

