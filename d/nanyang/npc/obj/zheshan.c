// Room: /d/nanyang/npc/obj/zheshan.c
// Last Modified by winder on Nov. 20 2001

#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name(CYN "ֽ����" NOR, ({ "zhe shan","fan"}) );
	set_weight(100);
        set("long","һ������ͨͨ�����ȣ������ϻ���һ��ɽˮ����\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 200);
		set("material", "bamboo");
	}
	init_dagger(1);
	set("wield_msg", "$N��һ�������������С�\n");
	set("unwield_msg", "$N�����е�$n���س������\n");
	setup();
}
