// Room: /d/5lt/fenghuanglin.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������Ǵ�˵�еķ���֡�
LONG);
	set("exits", ([
		"eastdown" : __DIR__"fanshudi",
	]));
        set("objects", ([
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -130);
	set("coor/y", 15);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}