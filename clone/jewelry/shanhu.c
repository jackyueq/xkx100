// shanhu.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"ɺ��"NOR, ({ "shan hu", "shanhu" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������Ŀ�⻪���߳�ɺ�����������\n");
		set("unit", "��");
		set("value", 50000 );
	}

}
