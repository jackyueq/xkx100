// Obj: /d/nanshaolin/obj/chaidao.c
// Last Modified by winder on May. 29 2001

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name("��",({"chai dao","dao"}));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit","��");
		set("value",50);
		set("material","black_steel");
		set("long","����һ�����ڿ���Ĳ񵶣������õ������ʮ�־�Զ��\n");
		set("wield_msg","$N�ó�һ�Ѳ��������\n");
		set("unwield_msg","$N���񵶷��¡�\n");
	}
	init_blade(10);
	setup();
}

