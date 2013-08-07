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
	object bag;
	object where;

	if ( !arg ) return 0;
	if ( query("book_count") < 1)
	{
		return notify_fail("�Ͳ�������ʲôҲû���ˡ�\n");
	}

	me = this_player();
	if ( arg == "bag")
	{
		where = environment(me);
message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+this_player()->query("name")+"�ҵ������澭����\n"NOR, users());
		message_vision(
"$N����ذ��Ͳ�������ʱ������ԭ�����ı������ľ��飬ֻ���Ͳ����ý��ܣ���
���ڲ���Գ��֮�У���ҳ��Ȼ�������\n", me);
		book = new("/clone/book/jiuyang1");
		book->move(file_name(where));
		book = new("/clone/book/jiuyang2");
		book->move(file_name(where));
		book = new("/clone/book/jiuyang3");
		book->move(file_name(where));
		book = new("/clone/book/jiuyang4");
		book->move(file_name(where));
		add("book_count",-1);
		bag = new(__DIR__"bag1");
		bag->move(environment());
		destruct(this_object());
	}
	return 1;
}
