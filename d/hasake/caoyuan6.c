// caoyuan6.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "���ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ���
�����ߣ�������ƥ�����������ǵĺ����⡣
LONG);
        set("exits", ([
           "southwest" : __DIR__"road2",
            "northwest" : __DIR__"room-ji",
            "east" : __DIR__"caoyuana",
            "north" : __DIR__"caoyuana",
            "south" : __DIR__"caoyuana",
            "west" : __DIR__"caoyuana",
        ]));
        set("outdoors", "hasake");
        setup();
        replace_program(ROOM);
}
