// Room: /d/5lt/sroad1.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ�������Ĵ��ӣ�һ���������ٵľ���������һ���ϱ����
��ʯ·�ϣ������и����¥����ɫ�Ľ���ӭ��Ʈ�ֻ�������ĸ�����
������Ŀ���û���¥�������濴�����Ǹ���ݣ�һ�������Ź��ʵ��˴���
�����������
LONG);
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"center",
            "south" : __DIR__"yanwuqiao",
            "west"  : __DIR__"jiulou1",
            "east"  : __DIR__"chaguan",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
