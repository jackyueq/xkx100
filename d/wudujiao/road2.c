// Room: /d/wudujiao/road2.c

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

        set("exits", ([
                "south" : __DIR__"road3",
                "north" : __DIR__"road1",
        ]));
        set("objects", ([
                "/d/taishan/npc/tiao-fu": 2,
        ]));

	set("coor/x", -45000);
	set("coor/y", -77000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}