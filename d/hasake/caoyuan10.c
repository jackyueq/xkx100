// caoyuan10.c ��ԭ
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
            "west" : __DIR__"caoyuan7",
            "east" : __DIR__"caoyuan8",
            "north" : __DIR__"caoyuan9",
        ]));
        set("objects", ([
                    __DIR__"npc/dingtong" : 1
        ]));
        set("outdoors", "hasake");
        setup();
        replace_program(ROOM);
}
