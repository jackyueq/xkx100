// Room: /d/xingxiu/cave.c
// Last Modified by Winder on Apr. 25 2001

inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
�������ɽ�����һ���ȳ�ζ�����۾���Ӧ�����������󣬲�
���ֵ�����һ��ɫ�ʰ�쵵ľ����������������ײҲҵĹǺ������˵�
������ض���̽��֮�ˣ�����ɽ����Ϊ����������
LONG
	);
	set("exits", ([
		"out" : __DIR__"shanshi",
	]));
	set("objects", ([
		__DIR__"npc/jumang" : 1,
		__DIR__"npc/snake" : 1,
	]));
	set("coor/x", -50400);
	set("coor/y", 20400);
	set("coor/z", 200);
	setup();
}
void init()
{
	add_action("do_use", "use");
	add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
	object me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me))  return 0;
	if(arg=="fire")
	{
		write("���ȼ�˻��ۣ���������ʯ������һ���ѷ죬�ƺ�������(zuan)��ȥ��\n");
		me->set_temp("marks/��", 1);
		me->start_busy(2);
		return 1;
	}
}

int do_zuan(string arg)
{
	object me = this_player();

	if(me->query_temp("marks/��") )
	{
		message("vision", me->name() + "����һ�²�֪��ʲô�ط����ȥ�ˡ�\n", environment(me), ({me}) );
		me->move(__DIR__"cave2");
		message("vision", me->name() + "��ʯ�������˽�����\n", environment(me), ({me}) );
		me->set_temp("marks/��", 0);
		return 1;
	}
	else {
		write("�������Ķ���?!\n");
		return 1;
	}
}

