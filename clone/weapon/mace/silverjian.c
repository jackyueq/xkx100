// silverjian.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
#include <ansi.h>
inherit MACE;

void create()
{
	set_name(HIW "��װ�" NOR, ({"silver mace", "mace", "silvermace", "yinjian", "jian"}));
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 8000);
		set("material", "silver");
		set("long", "һ�������������װﵣ���Ȼ�Ǳ��˲����ֲ���\n");
		set("wield_msg", "ֻ��һ������������$N�����Ѿ�����һ��$n��\n");
		set("unwield_msg", "$N������$n�����ܹ�âΪ֮һ����\n");
	}
	
	init_mace(65);
	setup();
}

