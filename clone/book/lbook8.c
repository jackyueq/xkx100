// lbook8.c
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"��˵�Ľ��֡�"NOR, ({ "literateb8", "shu8", "book8" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long","�Ȿ���Ƥ�е�ɣ�����д�š�˵�Ľ��֡������֡�\n");
		set("value", 10000);
		set("material", "paper");
		set("skill",
		([
			"name": "literate",
			"exp_required": 0,
			"jing_cost":    20,
			"difficulty":   15,
			"max_skill":    29,
			"min_skill":    1,
		]) );
	}
}
