// Room: /d/wudujiao/sl3.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һƬŨ�ܵ������֣�ǰ���Ѿ�û���˵�·������벻ʱ����
��������ǰ��֦�⡣���ڹ��ߺڰ����������������Լ��������� ��ֻ��
����ڵ��Ϻ�������Ϳ�֦�Ϸ�����ɳɳ����ǰ����ϡ͸��һ�������
�㲻�ɳ���������һ������
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"sl2",
//                "north" : __DIR__"pubu",
                "south" : __DIR__"sl5",
        ]));

	set("coor/x", -44920);
	set("coor/y", -81070);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}