// yujie.c

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name(CYN"���ָ"NOR, ({"yu jiezhi", "jiezhi", "finger"}));
	set_weight(500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����ɵĽ�ָ��Ө��Բ��\n");
		set("unit", "ö");
                set("value", 30000);
		set("material", "jade");
                set("armor_prop/armor", 3);
	}
	setup();
}

