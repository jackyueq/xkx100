// /d/quanzhen/shanlu1.c ɽ·
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
һ��ɽ·����������ͨ��ɽ�ϡ������ɽ�Ϻ�����һƬ�����֣�
����������¶��ͤ�ӵ�һ�ǣ����������ɽ��·��
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northeast" : __DIR__"shanlu2",
                "southeast" : __DIR__"shanlu3",
                "westdown"  : "/d/hanzhong/shanlu",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3150);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
