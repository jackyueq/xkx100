// mabukuanshan.c �鲼����

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�鲼����", ({"mabu kuanshan", "cloth"}));
	set_weight(1500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�׻�ɫ���鲼������\n");
		set("unit", "��");
		set("value", 300);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}

