// yayifu.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("���۷�", ({"yayi cloth", "cloth"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ɫ��װ��Ƕ�Ժ�ߣ������õ����۴��ġ�\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 500);
		set("armor_prop/armor", 10);
	}
	setup();
}

