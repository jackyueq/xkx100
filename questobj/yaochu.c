// weapon: /d/xingxiu/npc/obj/yaochu.c

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name(BLK"ҩ��"NOR, ({ "yao chu", "chu" }) );
	set("taskobj", 1);
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѳ�ҩ�õ�ҩ�����Ѿ���Щ�����ˡ�\n");
		set("value", 0);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	setup();
}

