// laozi1.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( "���¾�����һ�¡�", ({ "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			CYN
			"\n\t\t\t��һ��\n\n"
			"\n\t���ɵ����ǳ��������������ǳ�����\n"
			"\t�������֮ʼ����������֮ĸ��\n"
			"\t�ʳ��ޣ����Թ�������У����Թ����衣\n"
			"\t�����ߣ�ͬ����������ͬν֮������֮����������֮�š�\n\n"
			NOR
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
