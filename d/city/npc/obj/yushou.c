// yushou.c

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name(CYN"������"NOR, ({"yu shouzhuo", "shuozhuo" }));
	set_weight(500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����ɵ���������������Բ������\n");
		set("unit", "ö");
		set("value", 100000);
		set("material", "gold");
                set("armor_prop/armor", 10);
	}
	setup();
}

