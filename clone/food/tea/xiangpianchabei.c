// xiangpianchabei.c
// Last Modified by winder on May. 29 2001

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("��Ƭ�豭",({"xiangpian chabei", "cha", "chabei"}));
	set_weight(120);
	if (clonep())
		 set_default_object(__FILE__);
	else {
 		set("long", "һ���������Ƭ�裬���Ƶ�ð������~~~~~~\n");
		set("unit", "��");
		set("value", 30);
		set("remaining",10);
		set("drink_supply", 20);
	}
	set("liquid", ([
		"type": "tea",
		"name": "��",
		"remaining": 15,
		"drunk_apply": 5,
	]));
}

