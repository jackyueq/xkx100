// Room: /d/wudujiao/sl2.c

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
                "east" : __DIR__"sl3",
                "southwest" : __DIR__"sl4",
                "west" : __DIR__"sl1",
                "southeast" : __DIR__"sl5",
        ]));

	set("coor/x", -44930);
	set("coor/y", -81070);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}