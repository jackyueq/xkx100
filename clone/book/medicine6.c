// medicine6.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
	set_name(HIC"����ţҽ��"NOR, ({ "huqingniu yijing", "yijing", "jing"}));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","���ǵ���ҽ�ɺ���ţһ����Ѫ�㼯�ɵ�ҽ�顣\n");
		set("value", 1500);
		set("material", "paper");
		set("skill", ([
			"name":         "medicine",
			"exp_required": 100 ,
			"jing_cost":    30+random(10),
			"difficulty":   20,
			"min_skill":    100,
			"max_skill":    200
		]) );
	}
}
