// tjcloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("̫�����", ({ "taijian cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","����һ��̫����Σ���������һ��˵�����Ķ����\n");
		set("unit", "��");
		set("value", 60);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
	}
	setup();
}
