// Room: /d/wudujiao/sl5.c

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
	set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"sl3",
                "northwest" : __DIR__"sl2",
                "south" : __DIR__"sl8",
                "southwest" : __DIR__"sl7",
        ]));

	set("coor/x", -44920);
	set("coor/y", -81080);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}