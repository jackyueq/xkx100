// Room: /d/5lt/xiaoshulin.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����·��һƬС�����֣�����㲻�ϴ������п鿪���أ�ϰ���
�����Ǿ������������д����ա�
LONG );
	set("exits", ([
		"north" : __DIR__"eroad2",
	]));
        set("objects", ([
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -130);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}