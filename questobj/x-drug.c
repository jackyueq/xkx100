// x-drug.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIB"��"HIR"��"HIG"�ͺ�ɢ"NOR, ({ "yin yang san", "x-drug" }) );
	set_weight(80);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ǿ�ҵĴ�ҩ��\n");
		set("unit", "��");
		set("value", 0);
	}
}

