// pobuyi.c 
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("�Ʋ���", ({ "po buyi", "buyi", "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","����һ�����ò����Ĳ��£�Ҳ��֪������ûϴ���ˣ��������ǿ�����\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 0);
		set("armor_prop/armor", 1);
	}
	setup();
}

