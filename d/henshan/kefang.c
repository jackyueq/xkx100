// Room: /d/henshan/kefang.c
// Date: Sep.1 2001 by ahda

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
���Ǽ�����Ŀͷ������Ŵ������ţ����ߺܻ谵������������
ֻ�����߷��ż�����ʰ����������Ĵ󴲣����ž�������˯����
LONG );
	set("sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"east" : __DIR__"liufudayuan",
	]));
	set("coor/x", -410);
	set("coor/y", -1180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

