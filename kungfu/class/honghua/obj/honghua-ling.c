// honghua-ling.c �컨��
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name(HIR"�컨��"NOR, ({ "honghua ling","ling"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", HIG"����һ�������͵����ƣ�����컨���������֣��Ǻ컨���������ϵ����ơ�\n"NOR);
		set("value", 100000);
		set("material", "iron");
	}
	setup();
}

void init()
{
	call_out("dest", 1800);
}

void dest()
{
	destruct(this_object());
}
