// guishejiu.c ���߾ƺ�

#include <ansi.h>;
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���߾ƺ�", ({"guishe jiuhu", "jiu", "jiuhu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ���߾Ƶľƺ��������װһ��ľơ�\n");
		set("unit", "��");
		set("value", 300);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "���߾�",
		"remaining": 5,
		"drunk_apply": 3,
	]));
}
