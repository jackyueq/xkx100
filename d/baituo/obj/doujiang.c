// DOUJIANG.C ����

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("����",({ "jiang"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵĶ���������\n");
		set("unit", "��");
		set("value", 500);
        set("max_liquid", 4);
	}
	set("liquid", ([
		"type": "water",
		"name": "����",
		"remaining": 10,
		"drunk_supply": 10,
	]));
	setup();
}

