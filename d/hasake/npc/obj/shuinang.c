// shuinang.c  ˮ��

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ˮ��", ({"shuinang", "wineskin", "skin"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����װ����ˮ��ˮ�ҡ�\n");
		set("unit", "ֻ");
		set("value", 200);
		set("max_liquid", 300);
	}

	set("liquid", ([
		"type": "water",
		"name": "��ɽѩˮ",
		"remaining": 10,
		"drunk_apply": 30,
	]));
}
