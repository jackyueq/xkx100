// chaofu.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("����", ({ "chao fu", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","����һ���������Ǵ��ϳ�ʱ���ġ�\n");
		set("unit", "��");
		set("value", 60);
		set("material", "cloth");
		set("armor_prop/armor", 3);
		set("armor_prop/personality", 3);
	}
	setup();
}
