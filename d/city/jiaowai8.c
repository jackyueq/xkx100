// Room: /d/city/jiaowai8.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
�������ݽ����һƬ���ݵأ���Ӣ�ͷף������裬��¶Ϧ�⣬��
����Ƣ�������ѿ�����������ʱ��
LONG );
	set("exits", ([
		"south" : __DIR__"jiaowai7",
		"west"  : __DIR__"jiaowai9",
	]));
	set("objects", ([
		"/clone/medicine/vegetable/chuanshanjia" : random(2),
	]));
	set("outdoors", "yangzhoue");
	set("coor/x", 40);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}