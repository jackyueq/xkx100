// Room: /d/5lt/eroad2.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ�������Ĵ��ӣ�һ���������ٵľ���������һ���������
��ʯ·�ϣ���������һƬ���֣��ô�һƬ����ԣ�ӭ��ҡҷ��������Ȼ��
������һƬС���֡�
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "northeast" : __DIR__"zhulin",
            "south" : __DIR__"xiaoshulin",
            "west"  : __DIR__"eroad1",
            "east"  : __DIR__"qsroad",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");
	set("coor/x", -130);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}