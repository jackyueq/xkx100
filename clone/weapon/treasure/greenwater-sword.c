// greenwater-sword.c ��ˮ��
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
#include <ansi.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIG"��ˮ��"NOR, ({ "greenwater sword", "jian", "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ͨ�徧Ө��͸�Ľ�!\n");
		set("value", 400);
		set("material", "crimsonsteel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	init_sword(100);
	setup();
}
