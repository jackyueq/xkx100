// Room: /d/baituo/shuifang.c
// Last Modified by Winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "˯��");
	set("long", @LONG
���˯������������������ׯ���������ˡ���һ��������������
���м����飬ȴ�ǡ��׾���֮�ࡣǽ����һ�����ӡ��������俴��ȥ��
Ϊ������
LONG);
	set("no_fight", "1");
	set("objects", ([
		BOOK_DIR"bt_book5" : 1,
		BOOK_DIR"bt_book1" : 1,
	]));
	set("book_count",1);
	set("exits", ([
		"west" : __DIR__"tangwu",
	]));
	set("coor/x", -50000);
	set("coor/y", 20052);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	object book, me = this_player();

	if (random(me->query("kar")) > 20 && query("book_count") >= 1)
	{
		write("���߽���������ڴ���һ������Ȼ���ִ����¸���ʲô������\n");
		write("�ƿ�����һ����ԭ����һ����������װ�顣\n");
		book = new("/clone/book/bt_book");
		book->move(environment(me));
	}
	add("book_count", -1);
}
