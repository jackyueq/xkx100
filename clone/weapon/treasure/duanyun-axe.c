// duanyun-axe.c ���Ƹ�
// Last Modified by suncity on Feb. 13 2003

#include <ansi.h>;
#include <weapon.h>;
inherit AXE;
inherit F_UNIQUE;

void create()
{
	set_name(HIW"���Ƹ�"NOR, ({ "duanyun fu", "axe", "fu" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 10000);
		set("material", "iron");
		set("long", HIW"����һ�����������ĸ�ͷ��\n"NOR );
		set("wield_msg", HIW"һ���׹⣬$n����$N���У�ֻ�����ɷ��ƣ���Ϊ������\n"NOR);
		set("unwield_msg", HIW"$N�������е�$n�������������ؼ�ֻ��������\n"NOR);
	}
	init_axe(250);
	setup();
}
