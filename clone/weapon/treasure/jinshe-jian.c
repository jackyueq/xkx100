// jinshe-jian.c ���߽�
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
#include <ansi.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(YEL"���߽�"NOR, ({ "jinshe jian", "sword", "jian" }));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
"�⽣�����ã������������ǳ��أ��������ǻƽ�����������
��������������һ��Ѫ�ۣ����������͵İ��⣬���ǹ��졣����
��״�������أ�������������һ�����������ɣ���β���ɽ�����
��ͷ���ǽ��⣬��������ֲ棬���Խ��⾹�����档\n");
		set("value", 10000);
		set("material", "gold");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������У���ʱȫ�����쬵�ֻ�к������ˡ�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(130);
	setup();
}
