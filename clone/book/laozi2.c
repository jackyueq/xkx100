// laozi2.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( "���¾����ڶ��¡�", ({ "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			CYN "\n"
			"\n\t\t\t�ڶ���\n\n"
			"\t���½�֪��֮Ϊ����˹���ѡ���֪��֮Ϊ�ƣ�˹�����ѡ�\n"
			"\t����������������ɣ��������Σ�������ӯ��������ͣ�ǰ����\n"
			"�档��Ҳ��\n"
			"\t����ʥ�˴���Ϊ֮�£��в���֮�̣�����������ʼ���������У�\n"
			"Ϊ�����ѣ����ɶ����ӡ���Ψ���ӣ����Բ�ȥ��\n"
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
