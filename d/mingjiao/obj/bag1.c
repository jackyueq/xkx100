// bag.c
#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name("�Ͳ���", ({ "bag", "bao" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���Ͳ�������\n");
		set("value", 500);
		set("material", "cloth");
	}
	set("book_count", 1);
}

void init()
{
	if( this_player() == environment() )
	{
		add_action("do_open", "open");
		add_action("do_open", "unpack");
		add_action("do_open", "dakai");
	}
}

int do_open(string arg)
{
	object me, book;
	object where;

	if ( !id(arg) ) return 0;
	return notify_fail("�Ͳ�������ʲôҲû���ˡ�\n");
}
