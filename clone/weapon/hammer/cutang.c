// cutang.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit HAMMER;
inherit F_LIQUID;

void create()
{
	set_name("��̳��", ({"tanzi"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��װ�׵Ĵ�̳�ӣ�\n");
		set("unit", "��");
		set("value", 50);
		set("max_liquid", 5);
		set("wield_msg", "$Nץ��һ��$n���������е�������\n");
		set("material", "bone");
	}

	set("liquid", ([
		"type": "water",
		"name": "���",
		"remaining": 5,
	]) );
	init_hammer(5);
	setup();

}

