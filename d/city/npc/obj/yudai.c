// yudai.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(CYN"���"NOR, ({"yu dai", "dai" }));
	set_weight(500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����ɵ����������ϸ��������\n");
		set("unit", "ֻ");
                set("value", 120000);
		set("material", "gold");
                set("armor_prop/armor", 12);
	}
	setup();
}

