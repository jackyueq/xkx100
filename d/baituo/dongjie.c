// Room: /d/baituo/dongjie.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������С��Ķ��֡��ϱ��и������̣����洫������������������
���Ϸ��ǻ����ĸ�ڣ�����������С·����ɽ��
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"west"      : __DIR__"xijie",
		"south"     : __DIR__"datiepu",
		"southeast" : __DIR__"gebi",
		"northeast" : __DIR__"xiaolu1",
	]));
	set("objects",([
		__DIR__"npc/playboy" : 1,
	]));
	set("coor/x", -49980);
	set("coor/y", 19980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
