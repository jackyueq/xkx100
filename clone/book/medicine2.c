// medicine2.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"��٢����ͼ"NOR, ({"huatuo neizhaotu", "neizhaotu", "tu"}));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","���Ǿݴ���������ҽ��٢����������ҽ�顣\n");
		set("value", 1500);
		set("material", "paper");
		set("skill", ([
			"name":         "medicine",
			"exp_required": 1000,
			"jing_cost":    10,
			"difficulty":   20,
			"min_skill":    30,
			"max_skill":    60
		]) );
	}
}
