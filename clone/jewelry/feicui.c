// feicui.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(GRN"���"NOR, ({ "fei cui", "feicui" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�鰵������̶��ˮ�����䡣\n");
		set("unit", "��");
		set("value", 60000 );
	}

}
