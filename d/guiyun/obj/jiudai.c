// Obj: /d/guiyun/obj/jiudai.c
// Last Modified by winder on Jul. 9 2001

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("Ƥ�ƴ�", ({"jiudai"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ��ƵĴ�ƴ������װ���ġ������ľơ�\n");
		set("unit", "��");
		set("value", 60);
		set("max_liquid", 10);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "���",
		"remaining": 10,
		"drunk_apply": 3,
	]));
}
