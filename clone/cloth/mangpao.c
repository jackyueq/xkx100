// mangpao.c 
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("�������", ({"dahong mangpao", "pao", "cloth"}));
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ�����ɫ�ĳ��ۣ�����һ����������������ɽ�ӵ�ͼ�Ρ�\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 7000);
		set("armor_prop/armor", 15);

	}
	setup();
}

