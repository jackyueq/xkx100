// sifeng_huangxue.c �ķ�ɻ�ѥ

#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("�ķ�ɻ�ѥ", ({"sifeng huangxue", "xie", "shoes"}));
	set_weight(1000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ˫���ķ��Ƶ�Ƥѥ��������ʡ�\n");
		set("unit", "˫");
		set("value", 500);
		set("material", "pi");
		set("armor_prop/armor", 4);
		set("armor_prop/dodge", 10);
	}
	setup();
}



