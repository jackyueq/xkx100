// snow_sword.c 

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIB"���"HIW"ѩ��"HIG"��"NOR, ({"snowsword","xue jian","sword"}));
	set_weight(400);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "steel");
		set("long", "����һ����������Ľ�������ϸ���������ȷ�����\n");
		set("wield_msg", "$N���һ�ѽ���ϸ���Ľ����������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	setup();
}

