// lbook7.c
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"��˵�ɡ�"NOR, ({ "literateb7", "shu7", "book7" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long","�Ȿ���Ƥ�е�ɣ�����д�š�˵�ɡ������֡�\n");
		set("value", 5000);
		set("material", "paper");
		set("skill",
		([
			"name": "literate",
			"exp_required": 0,
			"jing_cost":    10,
			"difficulty":   15,
			"max_skill":    19,
			"min_skill":    1,
		]) );
	}
}
