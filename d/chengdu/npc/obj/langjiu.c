// langjiu.c �ɾ�ƿ

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�ɾ�", ({"lang jiu", "langjiu", "jiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һƿ�ɾƣ����װ������ľơ�\n");
		set("unit", "��");
		set("value", 200);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�ɾ�",
		"remaining": 5,
		"drunk_apply": 3,
	]));
}
