// mace.c
// Last Modified by winder on May. 25 2001

#include <weapon.h>
#include <ansi.h>

inherit MACE;

void create()
{
	set_name("��ͭ�", ({"copper mace", "mace", "coppermace", "tongjian", "jian"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
		set("material", "copper");
		set("long", "һ����������ͭﵣ�����ͭ��߰ߡ�\n");
		set("wield_msg", "$N����һ��$n���ڵ���ײ�������ǡ�\n");
		set("unwield_msg", "$NĨ��Ĩ$n�ϵ��⣬��������������\n");
	}
	init_mace(25);
	setup();
}

