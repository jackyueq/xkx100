// Room: /d/wudujiao/xiaolu.c

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
һ��С·�������죬���ܾ��ǻ������������ʱ��������
�ࡣǰ����һ��СС��ɽ�ԡ�
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "northwest" : __DIR__"road3",
                "southup" : __DIR__"shanlu2",
        ]));
        set("objects", ([
                "/d/wudang/npc/yetu": 3,
        ]));

	set("coor/x", -44000);
	set("coor/y", -78100);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}