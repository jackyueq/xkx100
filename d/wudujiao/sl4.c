// Room: /d/wudujiao/sl4.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һƬŨ�ܵ������֣�ǰ���Ѿ�û���˵�·������벻ʱ����
��������ǰ��֦�⡣���ڹ��ߺڰ����������������Լ��������� ��ֻ��
����ڵ��Ϻ�������Ϳ�֦�Ϸ�����ɳɳ����
LONG
        );
        set("outdoors", "wudujiao");
        set("exits", ([
                "north" : __DIR__"sl1",
                "northeast" : __DIR__"sl2",
                "south" : __DIR__"sl6",
                "southeast" : __DIR__"sl7",
        ]));
        set("objects", ([
                "/clone/medicine/nostrum/zhujingchan" : 1,
        ]));

	set("coor/x", -44940);
	set("coor/y", -81080);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}