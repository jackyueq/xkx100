// heiyi.c
// Last Modified by winder on May. 25 2001

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(HIB"����"NOR, ({"hemp cloth", "cloth"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIB"һ�����ư����е�λ�İ��ڳ��������¡�\n"NOR);
		set("material", "cloth");
		set("unit", "��");
		set("value", 240);
		set("armor_prop/armor", 4);
		set("armor_prop/personality", 1);
	}
	setup();
}

