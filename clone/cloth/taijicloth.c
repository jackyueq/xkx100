// taijicloth.c 
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("̫������", ({"taiji daopao", "cloth", "pao"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
"һ����ʿ���ĳ��ۣ�����̫�����ԣ�������������Ǭ����\n");
		set("unit", "��");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 4);
		set("armor_prop/spells", 5);
	}
}

