// yuzhan.c

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(WHT"��յ"NOR, ({ "yu zhan", "zhan" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "СС�����ʾ��ѡ�\n");
		set("unit", "��");
		set("value", 10000 );
		set("max_liquid", 20);
	}

}
