// Room: /d/nanyang/npc/obj/jiuhulu.c
// Last Modified by winder on Nov. 20 2001
//������������õĺ�«������commonװ���õģ����ԱȽϹ�

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
	set_name(YEL"�ƺ�«"NOR, ({"jiu hulu", "hulu", "pot"}));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�ƵĴ��«����Ƥ��ƣ�������װ�ü���ơ�\n");
		set("unit", "��");
		set("value", 300);
		set("max_liquid", 30);
	}
	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�ƾ�",
		"remaining": 30,
		"drunk_apply": 10,
	]));
}

