// tianchang-zhangpu.c �쳤�Ʒ���
// By sir 5/20/2001

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
	set_name(HIW"�쳤�Ʒ���" NOR, ({ "tianchang zhangpu","zhangpu", }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	     set("unit", "��");
	     set("long",
	"����һ�����ƾɵ�С�ᣬ���������һЩС�˻���ȭ�ŵ�ͼ�Ρ�\n",
	 );
	 set("value", 0);
	 set("material", "paper");
	 set("skill", ([
			"name":       "tianchang-zhang",
			"exp_required" : 10000,
			"jing_cost":  30,
			"difficulty": 20,
			"max_skill":  80
		]) );
	}
}
