// zhanpao.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("ս��", ({"zhan pao", "pao", "cloth"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "һ��ս�ۡ�\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 600);
		set("armor_prop/armor", 30);
	}
	setup();
}

