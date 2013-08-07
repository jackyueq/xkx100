// room: /d/xingxiu/tianroad4.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void init();
int do_jump(string arg);

void create()
{
	set("short", "��ɽɽ·");
	set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ
��Ҷ�֡�ʯ����ʢ����һ���׵���ɽѩ����һ����ҩ�����ڲ�ҩ����
��һ���(valley)��ס����ɽ��·��
LONG );
	set("exits", ([
	    "westup" : __DIR__"tianroad5"
	]));
	set("objects", ([
		__DIR__"npc/caiyaoren"  : 1,
		"/clone/medicine/vegetable/xuelian" : 1
	]));

	set("item_desc", ([
	"valley" : "������ɶ��������Ϊ��ߵ��Ƹߣ�Ӧ�ò�����(jump)��ȥ��\n"
	]) );
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");

	set("coor/x", -52000);
	set("coor/y", 20100);
	set("coor/z", 30);
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
		message("vision", me->name() + "һ������˫�������������\n", environment(me), ({me}) );
		me->move("/d/xingxiu/tianroad3");
		message("vision", me->name() + "�����������������\n", environment(me), ({me}) );
		return 1;
	}
}
