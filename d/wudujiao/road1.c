// Room: /d/wudujiao/road1.c

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
����һ�����ϵĻ��������������һƬƬ�����͵�ˮ��
�����е���ͯ������������������������������˶���������
����ͷ�󺹵ĴҴҸ�·���ƺ���������������������԰��⡣
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"road2",
                "north" : "/d/dali/luyuxi",
        ]));

	set("coor/x", -45000);
	set("coor/y", -76000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}