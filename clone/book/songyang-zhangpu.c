// songyang-zhangpu.c ����������
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
	set_name(RED"����������" NOR, ({ "songyang zhangpu","zhangpu", }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("long","����һ����ֽС�ᣬ���������һЩС�˻���ȭ�ŵ�ͼ�Ρ�\n",
	 );
	 set("value", 0);
	 set("material", "paper");
	 set("skill", ([
			"name"         : "songyang-strike",
			"exp_required" : 10000,
			"jing_cost"    : 30,
			"difficulty"   : 20,
			"max_skill"    : 80
		]) );
	}
}
