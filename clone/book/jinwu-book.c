// Last Modified by winder on Jul. 15 2001
// jinwu-book.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"���ڵ���"NOR, ({ "jinwu-book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ѧϰ���ڵ������顣\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	 "jinwu-blade",
			"exp_required": 10000,
			"jing_cost" :   30,
			"difficulty":   30,
			"max_skill":    100,
			"min_skill":    0
		]) );
	}
}

