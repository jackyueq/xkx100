// lbook2.c
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"���ټ��ա�"NOR, ({ "literateb2", "shu2", "book2" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);				   
	else
	{ 
	       set("unit", "��");
		set("long","�����˱ض��İټ��ա�\n");
		set("value", 200000);
		set("material", "paper");
		set("skill",
		([
			"name": "literate",
			"exp_required": 100,
			"jing_cost":    10,
			"difficulty":   15,
			"max_skill":    79,
			"min_skill":    50,
		]) );
	}
}
