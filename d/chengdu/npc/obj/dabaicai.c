// Room: /d/chengdu/npc/obj/dabaicai.c ��ײ�
// Last Modifyed by Winder on Jan. 4 2002

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ײ�", ({ "dabaicai", "baicai", "cai" }));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�ô�ײˡ�\n");
		set("unit", "��");
		set("value", 30);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
}
