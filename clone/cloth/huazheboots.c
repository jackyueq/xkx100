// huazheboots.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("����ѥ", ({ "huazhe xue", "flower boots", "boots" }) );
	set_weight(1700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long",
"һ˫Ƥѥ���ϵ�ţƤ�Ƴɡ������������ü����£�����ȥ���ɲ�����\n");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 1);
	}
	setup();
}

