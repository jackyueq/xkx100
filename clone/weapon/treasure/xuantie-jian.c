// xuantie-jian.c �����ؽ�
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
#include <ansi.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(WHT"�����ؽ�"NOR, ({ "iron sword", "jian", "sword" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",WHT@LONG
��ѽ����������࣬������ģ������߰�ʮ���ء������߽��涼�Ƕۿڣ�
�����ԲԲ�����Ǹ�����
LONG
NOR);
		set("value", 100000);
		set("material", "iron");
	}
	init_sword(160);
	set("no_drop", "�������������뿪�㡣\n");
	set("no_put","��˱���������ҷţ�\n");
	set("wield_msg", "ֻ������������һ���죬$N�γ���һ�Ѻ�����������ر�����$n��\n");
	set("unequip_msg", "$N�����е�$n���뱳�ϵĽ��ʡ�\n");
	setup();
}

