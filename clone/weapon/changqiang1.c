// changqiang.c ��ǹ

#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("��ǹ", ({ "chang qiang","qiang","changqiang" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�˱���ר�õĵľ��ֳ�ǹ,�����Ǳ�Ѱ��.\n");
		set("value", 0);
		set("material", "iron");
		set("long", "һ�˳�ǹ��\n");
		set("wield_msg", "$N����һ��$n��˳�ֶ��˸�ǹ����\n");
		set("unwield_msg", "$N����һ������$n��غ�����\n");
	}
	init_spear(100);
	setup();
}
