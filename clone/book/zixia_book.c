// zixia_book.c  ��ϼ��ܸ
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(MAG"��ϼ��ܸ"NOR, ({ "zixia_book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
//		set("no_drop",1);
		set("long",
HIM"�����书��������Ϊ������Ȼ������ԭΪ���ڣ�Ω���˲���
��֮�������Է��������֮�������Ա����Խ����Կᡢ������
�������Ŷ����ң��������������������ɥ�ʶ���ʧ������
�ĺݶ����١��������ߣ����ǽ���֮���⡣������ԣ�����
���ƣ����걩�ᣬ��������������ģ����񽬣������أ�ߵ
�������ݶ���֮������С�ɡ�\n"NOR);
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	 "zixia-shengong",	// name of the skill
			"exp_required": 50000,		// minimum combat experience required
								// to learn this skill.
			"jing_cost" :   30,
			"difficulty":   30,			// the base int to learn this skill
								// modify is gin_cost's (difficulty - int)*5%
			"max_skill":    99,			// the maximum level you can learn
			"min_skill":    0			// the maximum level you can learn
								// from this object.
		]) );
	}
}
int query_autoload() { return 1; }

