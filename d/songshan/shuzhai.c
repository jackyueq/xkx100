// Room: /d/songshan/shuzhai.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h>
int do_get();

string *book = ({
	"/clone/book/book-silk",
	"/clone/book/book-paper",
	"/clone/book/sword_book1",
	"/clone/book/sword_book4",
	"/clone/book/strike_book",
});

void create()
{
	set("short","��ի");
	set("long",@LONG
��������ɽ�ɵ���ի����ǽ��һ����ܣ�����������������һ����
�飬���Կ�ȥ�����伮���С��ϲ࿿�������������������ı��㱸��
LONG);
	set("exits",([
		"north" : __DIR__"eastting",
	]));
	set("book_count", 2);
	set("coor/x", 0);
	set("coor/y", 890);
	set("coor/z", 90);
	setup();
}
void init()
{
	add_action("do_get", "chou");
	add_action("do_get", "qu");
}
int do_get()
{
	object ob, me=this_player();
	me->add("qi", -5);
	if ((query("book_count") > 0) && (random(5) == 3))
	{
		ob=new(book[random(5)]);
		ob->move(me);
		message_vision(HIY"$N������Ϸ�����ȥ���˰��죬ȡ��һ��"+ob->query("name")+HIY"����\n"NOR,me);
		add("book_count", -1);
	}
	else 
		message_vision("$N������Ϸ�����ȥ���˰��죬Ҳ��֪������ɶ��\n",me);
	return 1;
}
