// jiasha.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
inherit F_UNIQUE;

void create()
{
	set_name(HIY"��������"NOR, ({ "jinlan jiasha", "jiasha", "cloth" }) );
	set("long", "һ��ɫ�ʰ�쵵Ľ�����ġ�\n");
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 90);
		set("armor_prop/dodge", 20);
		set("value", 50000);
	}
	setup();
}

