// magua.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("���", ({ "ma gua", "gua", "cloth"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������ɫ����ӣ�\n");
		set("unit", "��");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	setup();
}

