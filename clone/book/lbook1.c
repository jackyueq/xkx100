// lbook1.c
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"�����־���"NOR, ({ "literateb1", "shu1", "book1" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long","�����˱ض������־���\n");
		set("value", 50000);
		set("material", "paper");
		set("skill",
		([
			"name": "literate",
			"exp_required": 10,
			"jing_cost":    10,
			"difficulty":   15,
			"max_skill":    49,
			"min_skill":    20,
		]) );
	}
}
