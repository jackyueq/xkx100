// Obj: /d/lingxiao/obj/rice.c
// Last Modified by winder on Jul. 15 2001

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(HIW"���鷹"NOR, ({ "rice", "fan" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ѩɽ���������ķ���\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 15);
		set("material", "rice");
	}
	setup();
}

