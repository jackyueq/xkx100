// Room: /d/5lt/shanlu.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ����ɽ��С·��С·�����Ӳݴ����������������ˡ�����·
��ȴ����ƽ����������������һ�㡣ǰ���Ǹ���˿����������˿����
�����Ϸ��ˣ��㲻�ɼӿ��˽Ų���
LONG );
	set("exits", ([
		"eastup"   : __DIR__"5laofeng",
		"westdown" : __DIR__"caodi",
	]));
        set("objects", ([
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -115);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}