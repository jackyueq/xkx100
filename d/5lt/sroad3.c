// Room: /d/5lt/sroad3.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ�������Ĵ��ӣ�һ���������ٵľ���������һ���ϱ����
��ʯ·�ϣ�������һ�Ҵ����̣�����������������Զ����������������
�����������ġ�
LONG);
        set("exits", ([ /* sizeof() == 3 */
            "north" : __DIR__"sroad2",
            "west"  : __DIR__"datiepu",
            "east"  : __DIR__"tczhongxin",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}