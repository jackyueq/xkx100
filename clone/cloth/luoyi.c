// luoyi.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("��ˮ����", ({"luo yi", "fancy skirt", "skirt"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","���Ǽ��������ǳ����ŵĳ�ȹ��ȴ��֪��ʲô�Ƴɡ�\n");
		set("value", 1500);
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("armor_prop/dodge", 10);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

