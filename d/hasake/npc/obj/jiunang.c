// jiunang.c  �����

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�����", ({"jiunang", "wineskin", "skin"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ�ǲ�ԭ����Ĵ���ң�����װ�������������̾ơ�\n");
		set("unit", "ֻ");
		set("value", 250);
		set("max_liquid", 400);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "���̾�",
		"remaining": 10,
		"drunk_apply": 40,
	]));
}
