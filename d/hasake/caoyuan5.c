// caoyuan5.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "���ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ���
�����ߣ�������ƥ�����������ǵĺ����⡣
LONG);
        set("exits", ([
            "south" : __DIR__"road1",
            "west" : __DIR__"caoyuan4",
            "east" : __DIR__"caoyuan4",
            "north" : __DIR__"caoyuan4",
        ]));
        set("objects", ([
                    __DIR__"npc/hasake" : 1,
                    __DIR__"npc/yang" : 1
        ]));
        set("outdoors", "hasake");
        setup();
        replace_program(ROOM);
}
