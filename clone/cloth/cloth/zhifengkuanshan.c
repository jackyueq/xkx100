// zhifeng_huanshan.c ֱ�����

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("ֱ�����", ({ "zhifeng kuanshan", "cloth" }));
	set("long","һ�׿������Ĳ�����������غ����ʡ�\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 700);
		set("armor_prop/armor", 1);
	}
	setup();
}
