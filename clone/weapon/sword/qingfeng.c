// qingfeng.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("��潣", ({ "qingfeng sword", "jian", "sword" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 7000);
		set("material", "steel");
		set("long", "����һ����ϸ�ֳ��Ľ�������������\n");
		set("wield_msg", "һ�����������$N�����Ѷ��˰�$n��\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_sword(65);
	setup();
}
