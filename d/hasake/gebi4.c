// gebi1.c
#include <room.h>
inherit ROOM;
void create()
{
       set("short","�������");
       set("long", @LONG
��������Ĵ��ڣ�Ҫ�߳����ﲢ�����¡���Զ������ɳ�������
�ذ㴵��������Ҫ��籩�ˡ�
LONG);
        set("exits", ([
                "north" : __DIR__"gebi2",
                "south" : __DIR__"gebi3",
                "east" : __DIR__"gebi1",
                "west" : __FILE__,
        ]));
        set("outdoors", "hasake");
        set("no_quest",1);
        setup();
}
#include "gebi.h";