// Room: /d/chengdu/npc/obj/piang.c ���޷�Ƭ
// Last Modifyed by Winder on Jan. 4 2002

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���޷�Ƭ", ({"piang"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����޷�Ƭ��\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 6);
		set("food_supply", 120);
	}
}
