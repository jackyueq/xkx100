// Room: /d/gumu/obj/yinsuo.c
// Last Modifyed by Winder on Jan. 14 2002

#include <weapon.h>;
#include <ansi.h>;

inherit WHIP;
inherit F_UNIQUE;

void create()
{
	set_name(HIW"����"NOR,({ "yin suo", "whip","bian","suo" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("unique", 1);
		set("rigidity", 3);
		set("material", "softsteel");
		set("weapon_prop/dodge", 5);
		set("weapon_prop/parry", 3);
		set("treasure",1);
		set("wield_neili", 200);
		set("wield_maxneili", 1000);
		set("wield_str", 20);
		set("long", "һ����ɫ�����ĩ�˻�ϵ��һ����ɫ��Բ��\n");
		set("unwield_msg",HIY"$N����һ�������������뻳�С�\n"NOR);
		set("wield_msg",HIY"$N�����ӻ���ȡ��һ�ű�篰��������������֮�ϡ�\n"NOR);
	}
	init_whip(100);
	setup();
}

