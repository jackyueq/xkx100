// Room: /d/huijiang/obj/xiangcha.c ���
// Last Modified by winder on Sep. 12 2001

inherit ITEM;
void init();

void create()
{
	set_name("���",({"tea", "cha", "xiang cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���Ȳ裬���Ƶ�ð������������\n");
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

