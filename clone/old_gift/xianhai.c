// Last Modified by winder on Apr. 25 2001
// xianhai.c �ݺ���

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "�ݺ���" NOR, ({ "card", "throw card"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�Ź��صĿ�Ƭ����˵���������ݺ����ˡ�\n");
		set("value", 1);
		set("no_sell", 1);
		set("unit", "��");
		set("time_to_leave", 20);
	}
}
