// Room: /d/5lt/wroad3.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ�������Ĵ��ӣ�һ���������ٵľ���������һ���������
��ʯ·�ϡ��������������С����Ҭ����ӳ�£���֪ͨ�����
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "northwest" : __DIR__"xiaodao",
            "southup"   : __DIR__"shijie",
            "west"      : __DIR__"wroad4",
            "east"      : __DIR__"wroad2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -180);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}