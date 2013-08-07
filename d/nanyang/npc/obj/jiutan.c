// Room: /d/nanyang/npc/obj/jiutan.c
// Last Modified by winder on Nov. 20 2001

inherit ITEM;
#include <ansi.h>
inherit F_LIQUID;
void create()
{
	set_name(YEL "�ƾ�̳��" NOR, ({"jiu tanzi", "tanzi", "pot"}));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�ƾƵĴ���̳�ӣ���������ź�ֽ��\n");
		set("unit", "��");
		set("value", 800);
		set("max_liquid", 120);
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
