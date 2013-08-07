// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","��Ҷ��");
       set("long", "���Ǽ�����ɽ���µ�һƬ��Ҷ�֣��������޳�Ⱥ�������̸��ź��һ
�����롣��������һ�����ʵ�ɽ��������ɽ�ˣ�ɽ�������ѩ��ɽ��ȴ��
���������������߱��Ǵ��ԭ�������ڵĹ��������������������\n");

        set("exits", ([
             "south" : __DIR__"senlin1",
             "north" : __DIR__"senlin"+(1+random(4)),               
             "west"  : __DIR__"senlin"+(1+random(4)),               
             "east"  : __DIR__"senlin"+(1+random(4)),               
        ]));
        
        set("objects", ([
                         __DIR__"npc/bird" : 1,
        ]));

        set("outdoors", "hasake");

        setup();
       replace_program(ROOM);
}