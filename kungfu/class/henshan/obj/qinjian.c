// qinjian.c
// Last Modified by winder on Sep. 2 2001

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�ٽ�", ({ "qin jian", "jian", "sword" }) );
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 700);
		set("material", "steel");
		set("long", "����һ����ϸ�ֳ��Ľ������ֲ��ں�����Ǻ�ɽ������Ī���������佣��\n");
		set("wield_msg", "ֻ����������һ�����죬$N���ٵ׳��һ�Ѽ�ϸ�����Ľ�����\n");
		set("unequip_msg", "��������һ���죬$N���ְѽ���غ��ٵס�\n");
		set("weapon_prop/courage", -4);
	}
	init_sword(50);
	setup();
}
