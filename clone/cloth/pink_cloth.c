// pink_cloth.c
// Last Modified by winder on May. 25 2001

#include <armor.h>;
#include <ansi.h>;
inherit CLOTH;

void create()
{
	set_name(HIM"�ۺ����"NOR, ({"hong choushan", "pink cloth", "cloth"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
"����ۺ�ɫ�ĳ����������ż�ֻ��ȵ������������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

