// qingshajin.c

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
	set_name(GRN "��ɴץ��ͷ��" NOR, ({ "qingsha jin", "head" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",600);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
