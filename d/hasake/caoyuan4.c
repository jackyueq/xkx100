// caoyuan4.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "���ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ���
�����ߣ�������ƥ�����������ǵĺ����⡣
LONG);
        set("exits", ([
            "south" : __DIR__"caoyuan5",
            "west" : __DIR__"caoyuan5",
            "east" : __DIR__"caoyuan5",
            "north" : __DIR__"caoyuan5",
        ]));
        set("outdoors", "hasake");
        setup();
        replace_program(ROOM);
}
