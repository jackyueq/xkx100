// Room: /d/5lt/wroad4.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ�������Ĵ��ӣ�һ���������ٵľ���������һ���������
��ʯ·�ϡ�����������С·��Ҭ����ӳ�£���֪ͨ�����
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "northwest" : __DIR__"xiaolu",
            "south"     : __DIR__"kongdi",
            "east"      : __DIR__"wroad3",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -190);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}