// Room: /d/5lt/wroad2.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ�������Ĵ��ӣ�һ���������ٵľ�����������һ���������
��ʯ·�ϡ�
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "west"  : __DIR__"wroad3",
            "east"  : __DIR__"wroad1",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");
	set("coor/x", -170);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}