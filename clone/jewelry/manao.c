// manao.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM"���"NOR, ({ "ma nao", "manao" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�龧Ө���ŵ���觡�\n");
		set("unit", "��");
		set("value", 70000 );
	}

}
