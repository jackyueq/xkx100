// qingguang-jian.c ��⽣
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
#include <ansi.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIC"��⽣"NOR, ({ "qingguang jian", "jian", "sword" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",HIC"��ѽ���Լ�ĳߣ������������ȷ�ǰ�������\n"NOR);
		set("value", 10000);
		set("material", "steel");
	}
	init_sword(120);
	set("no_drop", "�������������뿪�㡣\n");
	set("no_put","��˱���������ҷţ�\n");
	set("wield_msg", "ֻ������쬡���һ����$N�������Ѿ�����һ��������亮�����˵���������$n��\n");
	set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	setup();
}
