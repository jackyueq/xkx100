// lbook3.c
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"��ǧ���ġ�"NOR, ({ "literateb3", "shu3", "book3" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long","�����˱ض���ǧ���ġ�\n");
		set("value", 500000);
		set("material", "paper");
		set("skill",
		([
			"name": "literate",
			"exp_required": 1000,
			"jing_cost":    10,
			"difficulty":   15,
			"max_skill":    99,
			"min_skill":    80,
		]) );
	}
}
int query_autoload()
{
	return 1;
}
