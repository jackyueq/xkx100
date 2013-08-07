// sroad3.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@LONG
�����ǿ��������ĳ�ɽ���룬��ʯ��ᾡ�������ȥ���Ǵ�����Ե�ˡ�
������һ��ѩɽ�������ơ�·������һ����ѩ��(hollow)��
LONG );
	set("exits",([
		"northwest" : "/d/lingxiao/boot",
		"eastdown"  : __DIR__"sroad2",
		"northdown" : __DIR__"nroad1",
		"westup"    : __DIR__"sroad4",
	]));
	set("objects",([
		__DIR__"npc/liuchengfeng" : 1,
	]));
	set("item_desc",([
		"hollow"  : "һ��ѩ�ӣ��ƺ�������(jump)��ȥ��\n"
	]));
	set("outdoors", "xueshan");
	set("no_clean_up", 0);
	set("coor/x", -30000);
	set("coor/y", -10000);
	set("coor/z", 50);
	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me = this_player();
	if( arg=="hollow")
	{
		message_vision("$N����������������ѩ����һ������ߴһ��ˤ���ӵס�\n",me);
		me->move(__DIR__"hollow");
	}
	else
	{
		message_vision("$N��������������ѩ����һ����ſ�ڵ����ˡ�\n",me);
	}
	return 1;
}
