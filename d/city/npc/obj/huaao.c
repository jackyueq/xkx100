//Cloth :huaao.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("�廨�̰�", ({ "hua ao", "cloth"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���廨�ĵĲ�������С�˵㣬������ͯװ��\n");
		set("unit", "��");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("kid_only", 1);
		set("female_only", 1);
	}
	setup();
}
