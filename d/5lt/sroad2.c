// Room: /d/5lt/sroad2.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ�������Ĵ��ӣ�һ���������ٵľ���������һ���ϱ����
��ʯ·�ϣ������и��ʾ֣���ʱ�����ŵ��ʲ����Ž�̤��ߺ���Ŵ�����
���ӹ������߾��ǡ������������ˡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"yanwuqiao",
            "south" : __DIR__"sroad3",
            "west"  : __DIR__"youju",
            "east"  : __DIR__"zhensuo",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
