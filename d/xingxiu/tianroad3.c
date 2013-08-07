// room: /d/xingxiu/tianroad3.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void init();
int do_jump(string arg);

void create()
{
	set("short", "��ɽɽ·");
	set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ
��ԭ������һ���(valley)��ס����ɽ��·��
LONG );
	set("exits", ([
		"northup"  : __DIR__"xxroad4",
		"eastdown" : __DIR__"xxh",
	]));
	set("item_desc", ([
		"valley" : "������ɶ����֪���ܲ�����(jump)��ȥ��\n"
	]) );
	set("objects", ([
		CLASS_D("xingxiu")+"/azi" : 1
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -51000);
	set("coor/y", 20100);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="valley" )
	{
/*		if (present("horse", me)) { */
		if (me->query_temp("marks/��") )
		{
			message("vision", me->name() + "�͵�һ�����������µ�������һ����˻Խ�������\n", environment(me), ({me}) );
			write("���͵�һ�����������µ�������һ����˻Խ�������\n");
			me->move("/d/xingxiu/tianroad4");
			message("vision","ֻ����������һ����˻��" + me->name() + "������Ƕ��������˹��������Ƶ�������\n̴Ϫ�����¹���\n", environment(me), ({me}) );
			write( "ֻ����������һ����˻���������Ƕ��������˹��������ǿ���ˡ�\n���ֵô����Ϲ���������\n");
			me->set_temp("marks/��", 0);
			return 1;
		}
		else
		{
			write("�������ԣ���������Ǳ߱���߸ߣ�����������������ȥ�ġ�\n");
			return 1;
		}
	}
}
