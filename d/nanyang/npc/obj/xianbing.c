// Room: /d/nanyang/npc/obj/xianbing.c
// Last Modified by winder on Nov. 20 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�ڱ�", ({"xian bing", "bing"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ý��ƽ��Ƶ��ڱ���\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 2);
		set("food_supply", 40);
	}
}

