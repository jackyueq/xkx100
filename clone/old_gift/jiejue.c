// Last Modified by winder on Apr. 25 2001
// jiejue.c ��ȿ�

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "��ȿ�" NOR, ({ "card", "help card"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ�ž�Ө��͸�Ŀ�Ƭ����˵�������Խ�����ݵ����е��ˡ�\n");
		set("value", 1);
		set("no_sell", 1);
		set("unit", "��");
	}
}
