// feixue-book.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"��ѩ����"NOR, ({ "feixue-book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ѧ��ѩӳ÷�Ƶ��顣\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	 "snow-strike",
			"exp_required": 10000,
			"jing_cost" :   20,
			"difficulty":   20,
			"max_skill":    80,
			"min_skill":    20
		]) );
	}
}

