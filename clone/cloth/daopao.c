// daopao.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("��ɫ����", ({  "dao pao", "pao", "cloth"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������ͨͨ�ĻҲ����ۡ�\n");
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
