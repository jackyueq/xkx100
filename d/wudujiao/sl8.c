// Room: /d/wudujiao/sl8.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һƬŨ�ܵ������֣�ǰ���Ѿ�û���˵�·������벻ʱ����
��������ǰ��֦�⡣��Զ��һ��ǧ��Ĺ���ֱ���������������ݺύ��
�������ƺ���������˵���ƾõ����¡����ڹ��ߺڰ�����������������
���������� ��ֻ������ڵ��Ϻ�������Ϳ�֦�Ϸ�����ɳɳ����ǰ��
��ϡ͸��һ˿�������㲻�ɸ��˵Ľ��߼�����
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"sl5",
                "west" : __DIR__"sl7",
        ]));

	set("coor/x", -44920);
	set("coor/y", -81090);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}