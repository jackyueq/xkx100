// Room: /d/city/jiaowai1.c
// Jan. 8.1998 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
�������ݽ����һƬ���ݵأ���Ӣ�ͷף������裬��¶Ϧ�⣬��
����Ƣ�����Ǻ�ʱ�⡣ż�м���С��Ů���̤�࣬ݺ����Ӱ�����ֶ��ˡ�
LONG );

	set("exits", ([
		"north" : __DIR__"dongmen",
		"south" : __DIR__"jiaowai2",
		"east"  : __DIR__"deshengshan",
	]));

	set("no_clean_up", 0);
	set("outdoors", "yangzhoue");
	set("coor/x", 70);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}