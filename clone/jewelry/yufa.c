// yufa.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(CYN"����"NOR, ({"yu fazan", "fazan" }));
	set_weight(500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����ɵķ���������������Բ������\n");
		set("unit", "ö");
                set("value", 50000);
		set("material", "gold");
                set("armor_prop/armor", 5);
                set("female_only", 1);
	}
	setup();
}

