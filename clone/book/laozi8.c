// laozi8.c
// by Marz

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( "���¾����ڰ��¡�", ({ "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			CYN "\n"
			"\n\t\t\t�ڰ���\n\n"
			"\t������ˮ��ˮ���������������������֮���񣬹ʼ��ڵ���\n"
			"\t���Ƶأ�����Ԩ�������ʣ������ţ������Σ������ܣ�����ʱ��\n"
			"��Ψ�����������ȡ�\n"
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
