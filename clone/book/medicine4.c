// medicine4.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"������ľ�"NOR,({"ziwu zhenjiujing","ziwu","jing"}));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","���ǵ���ҽ�ɺ���ţ����ҽ�顣\n");
		set("value", 15000);
		set("material", "paper");
		set("skill", ([
			"name":         "acupuncture",
			"exp_required": 100,
			"jing_cost":    10,
			"difficulty":   20,
			"max_skill":    50
		]) );
	}
}
