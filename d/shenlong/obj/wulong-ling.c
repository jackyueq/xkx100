// lingpai.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"����"NOR, ({ "lingpai", "pai" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("value", 50);
		set("material", "wood");
		set("long", "����һ֧ľ���ƣ�����������д��һ�������������֡�\n");
	}
	setup();
}
