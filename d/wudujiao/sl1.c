// Room: /d/wudujiao/sl1.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���߽���һƬŨ�ܵ������֣�ǰ���Ѿ�û���˵�·������벻ʱ����
��������ǰ��֦�⡣���ڹ��ߺڰ����������������Լ��������� ��ֻ��
����ڵ��Ϻ�������Ϳ�֦�Ϸ�����ɳɳ����
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"wdsl8",
                "east" : __DIR__"sl2",
                "south" : __DIR__"sl4",
        ]));

	set("coor/x", -44940);
	set("coor/y", -81070);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}