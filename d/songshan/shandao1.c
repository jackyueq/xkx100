// Room: /d/songshan/shandao1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
��������ɽ����ɽ���ϣ����ɴ�أ�ɽ�����ʱ��Ʈ�������ͨ
����ĸʯ��������¬���ٲ���
LONG );
	set("exits", ([
		"southdown" : __DIR__"dadian",
		"northwest" : __DIR__"qimushi",
		"northeast" : __DIR__"luyasi",
		"southeast" : __DIR__"yunutai",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	set("coor/x", 0);
	set("coor/y", 740);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
