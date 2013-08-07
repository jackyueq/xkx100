// /d/xingxiu/silk3.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;
int do_climb(string arg);

void create()
{
	set("short", "˿��֮·");
	set("long", @LONG
����һ����ԭ������֮����̵����������������ɽ�����������
���º�����һ���������������ԭ��������ͨ������������һ����ɳ
�ѻ��γɵ�ɽ(mount)��
LONG );
	set("outdoors", "silu");
	set("exits", ([
		"eastup"    : __DIR__"songmoya",
		"west"      : __DIR__"shimen",
		"northwest" : __DIR__"yanzhishan",
	]));
	set("objects", ([
		"/d/hangzhou/honghua/huo" :1,
		__DIR__"npc/trader" : 1,
	]));
	set("item_desc", ([
		"mount" : 
		"����һ����ɳ�ѻ��γɵ�ɽ��΢�紵����ɳɽ�������˵���������\n" 
		"��������Ȼ�����﷢�����Ե���̾��\n"
	]) );
	set("no_clean_up", 0);
	set("coor/x", -21500);
	set("coor/y", 600);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}
int do_climb(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="mount")
	{
		message("vision", me->name() + "�ԳԿԳ���ɳɽ����ȥ��\n", environment(me), ({me}) );
		me->move("/d/xingxiu/shashan");
		message("vision", me->name() + "��ɳɽ������������ճ��һ��ɳ�ӡ�\n", environment(me), me );
		return 1;
	}
}

#include "/d/xingxiu/job2.h";

