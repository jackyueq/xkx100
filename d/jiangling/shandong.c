//Edited by fandog, 02/18/2000
#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
�������ݷ������������ˣ�������������ĵ�����׽ɽ�õİ����
�ݷ���ţʱ���Ķ̵ѣ����ڶ����ʯ�ϡ��Ǳ����ݷ��������������е�
�����������˻��⡣�������л���һ�����飬�����ݷ�������Ь������
�����ġ�
LONG );
	set("exits", ([
		"out"  : __DIR__"dashandong",
	]));
	set("book_count", 1);
	set("no_clean_up", 0);
	set("coor/x", -1640);
	set("coor/y", -2210);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_pick","pick");
}

int do_pick(string arg)
{
	object obj, me = this_player();
	if( !arg || arg!="book" ) return notify_fail("��Ҫ��ʲô?\n");
	if( query("book_count") )
	{
		obj = new (__DIR__"obj/tangshi");
		obj->move(me);
		add("book_count", -1);
		message_vision("$N���ִ�������������һ�����飬��ķ�����д�š���ʫѡ�����ĸ��֡�\n",me );
message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"�õ���ʫѡ������\n"NOR, users());
	}
	else
		return notify_fail("��Ҫ�����Ǳ��飬ȴ�����㿴�����ۣ���ʵ����ʲô��û�С�\n");
	return 1;
}