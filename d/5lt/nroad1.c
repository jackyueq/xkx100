// Room: /d/5lt/nroad1.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ�������Ĵ��ӣ�һ���������ٵľ���������һ���ϱ����
��ʯ·�ϣ�������һ������ݣ��ճ�¯�����������ζ���㴹�����Ρ�
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "north" : __DIR__"shiqiao",
            "south" : __DIR__"center",
            "west"  : __DIR__"mianbaowu",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}