// Room: /d/fuzhou/xichansi.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ʼ�����������������¥���Ϊ�����ͣ�����ׯ�ϣ�����
��𲻾�������������������󣬶�����顣
LONG );
	set("exits", ([
		"north" : __DIR__"xixiaojie",
	]));
	set("objects", ([
		"/d/wudang/npc/guest" : 1,
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
