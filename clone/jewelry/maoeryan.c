// maoeryan.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(GRN"è����"NOR, ({ "maoer yan", "yan" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����̶����ź���ı�ʯ��\n");
		set("unit", "��");
		set("value", 100000 );
	}

}
