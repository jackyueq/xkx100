// maxie.c  ��Ь

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("��Ь", ({"ma xie", "xie", "shoes"}));
	set_weight(1000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ˫�������Ƶ�Ь�ӡ�\n");
		set("unit", "˫");
		set("value", 5);
		set("material", "silk");
		set("armor_prop/armor", 1);
	}
	setup();
}


