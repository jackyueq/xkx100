//langyamace.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
#include <ansi.h>
inherit MACE;

void create()
{
	set_name("������", ({"langya bang", "mace", "langyabang", "langya"}));
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 18000);
		set("material", "iron");
		set("long", "�ںڵ��������������˵��̣����˲��ɵ���Ȼ��η��\n");
		set("wield_msg", "$N��������һ�����һ��$n����ݺݵض�����Χ���ˣ�\n");
		set("unwield_msg", "$NС�����������$n����㱻���������Լ���\n");
	}
	
	init_mace(35);
	setup();
}

