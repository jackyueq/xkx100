// king-blade.c ��������
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
inherit BLADE;
inherit F_UNIQUE;

void create()
{
	set_name("��������", ({ "chuangwang baodao", "blade", "dao" }) );
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "iron");
		set("long", "���Ǵ�����ʹ�ù��ĵ���������м���С�֡�\n" );
		set("wield_msg", "һ���׹⣬$n����$N���У�ֻ��������䣬����͸�ǣ�����������Ĵ����ս��\n");
		set("unwield_msg", "$N��$n������䣬�����������ؼ�ֻ��������\n");
	}
	init_blade(250);
	setup();
}
