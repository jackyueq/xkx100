// wineskin.c  �ƴ�

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("����", ({"ke le", "ke", "le"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����˱���Ŀ��֡�\n");
		set("unit", "��");
		set("value", 20);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "",
		"remaining": 15,
		"drunk_supply": 6,
	]));
}

