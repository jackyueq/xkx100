// baiduanshan.c  �׶���

#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("�׶���", ({"baiduan shan", "cloth"}));
	set_weight(1000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "һ�װ�ɫ�ĳ���������Ʈ�ݡ�\n");
		set("unit", "��");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 2);
	}
	setup();
}
