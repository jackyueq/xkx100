// Room: /d/wudujiao/shixi.c

inherit ROOM;

void create()
{
        set("short", "ʯ϶");
        set("long", @LONG
������һ����ʯ�ķ�϶��խ��Ҫ�˲����������������۵��ҷ�
��ǰ��ȥ�����ܺ�����ģ�ֻ�н��µ�ɰʯ������΢�����졣
LONG
        );

	set("no_clean_up", 0);
        set("exits", ([
              "down"     : __DIR__"baidu2",
              "westdown" : __DIR__"mishi",
        ]));

	set("coor/x", -44950);
	set("coor/y", -81120);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}