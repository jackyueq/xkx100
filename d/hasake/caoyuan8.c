// caoyuan8.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "���ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ���
�����ߣ�������ƥ�����������ǵĺ����⡣
LONG);
        set("exits", ([
            "south" : __DIR__"caoyuan9",
            "west" : __DIR__"caoyuana",
            "east" : __DIR__"caoyuan7",
            "north" : __DIR__"room-che",
        ]));
        set("outdoors", "hasake");
        setup();
        replace_program(ROOM);
}
