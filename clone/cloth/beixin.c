// beixin.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name( "Ƥ����", ({ "pi beixin", "beixin" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ˮţƤ�Ƶı��ģ��䲻���£����ܽ�ʵ��\n");
		set("unit", "��");
		set("value", 400);
		set("material", "leather");
		set("armor_prop/armor", 6);
	}
	setup();
}

