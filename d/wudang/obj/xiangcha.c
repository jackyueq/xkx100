// xiangcha.c ���

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���",({"tea", "cha", "xiang cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���Ȳ裬���Ƶ�ð������������\n");
		set("unit", "��");
		set("value", 1000);
		set("max_liquid", 20);
	}
	set("liquid", ([
		"type": "tea",
		"name": "��",
		"remaining": 2,
		"drunk_apply": 25,
	]));
}
