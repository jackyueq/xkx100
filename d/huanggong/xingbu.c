// Room: /d/huanggong/xingbu.c

inherit ROOM;

void create()
{
	set("short", "�̲�����");
	set("long", @LONG
����������֮��--�̲���Ա�򳯵ĳ���.
LONG
	);
        set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"zuomen",
	]));
	set("coor/x", -220);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}