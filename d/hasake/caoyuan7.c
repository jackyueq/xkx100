// caoyuan7.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "���ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ���
�����ߣ�������ƥ�����������ǵĺ����⡣
LONG);
        set("exits", ([
            "south" : __DIR__"caoyuana",
            "west" : __DIR__"caoyuan9",
            "east" : __DIR__"caoyuan8",
            "north" : __DIR__"room-su",
        ]));
        set("outdoors", "hasake");
        setup();
        replace_program(ROOM);
}
