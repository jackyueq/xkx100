// Room: /d/huijiang/npc/obj/yangrou.c
// Last Modified by winder on Sep. 12 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({ "meat" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�鷢��ǿ����ζ������.\n");
		set("unit", "��");
		set("value", 1000);
		set("eat_msg","$Nҧ��һ��$n��ͻȻ������Ӭ��£���������\n");
		set("food_remaining",8);
		set("food_supply", 60);
	}
}
