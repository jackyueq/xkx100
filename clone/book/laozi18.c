// laozi18.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( "���¾�����ʮ���¡�", ({ "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			CYN "\n"
			"\n\t\t\t��ʮ����\n\n"
			"\t����ϣ������壻�ǻ۳����д�α�����ײ��ͣ���Т�ȣ����һ�\n"
			"�ң����ҳ���\n"
			"\n"NOR
		);
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name"        : "taoism",
			"exp_required":	0,
			"jing_cost"   : 10,
			"difficulty"  : 15,
			"max_skill"   : 29,
		]) );
	}
}
