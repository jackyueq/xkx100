// Room: /d/huanggong/kunningmen.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǻʹ���͢�ĺ���. ����������԰. ��������������, �ɴ˽���
��ν��������Ժ.
LONG
	);
	set("outdoors", "huanggong");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"kunninggong",
		"north"     : __DIR__"yuhuayuan",
	]));
	set("objects", ([
		__DIR__"npc/ruidong" : 1,
	]));
	set("coor/x", -200);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "south" &&
	objectp(present("rui dong", environment(me))))
		return notify_fail("����ס��˵���˴����أ���ֹ����\n");

	return ::valid_leave(me, dir);
}