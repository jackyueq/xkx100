// mabutoujin.c

#include <armor.h>
inherit HEAD;
void create()
{
	set_name("�鲼ͷ��", ({ "mabu toujin", "head" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",50);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
