// literateb5.c ����
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"�����"NOR, ({ "literateb5", "shu5", "book5"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","һ���׷��ӵġ������\n");
		set("value", 400);
		set("material", "paper");
		set("skill", ([
			"name": "literate",
			"exp_required": 100000,
			"jing_cost":	20,
			"difficulty":   30,
			"max_skill":   149,
			"min_skill":   130,
		]) );
	}
}
int query_autoload() { return 1; }
