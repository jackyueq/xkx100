// pinkshirt.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIR"��ɫ÷ǳ��ȹ"NOR, ({"qianhong qun","pink skirt","skirt"}));
	set_weight(2700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һϮ��ȹ���������˼���ˮ����\n");
		set("unit", "Ϯ");
		set("value", 3000);
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("armor_prop/dodge", 10);
	}
	setup();
}

