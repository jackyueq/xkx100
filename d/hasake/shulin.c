// shulin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short",HIY"ɽ��"NOR);
       set("long", @LONG
ͻȻ֮�䣬������������һƬɽ�꣬ɽ����ľ�ԴУ��ڸ����ͻȻ������
�������������ɽһ�㡣�������������������ɳ����Ƭɽ����ס�ˣ�
���Զ����ȫ��������
LONG);
        set("exits", ([
                "west" : __DIR__"gebi2",
                "south" : __DIR__"gebi1",
                "east" : __DIR__"gebi4",
                "northwest" : __DIR__"shulin1",
        ]));
        set("outdoors", "hasake");
        set("no_quest",1);
        setup();
       replace_program(ROOM);
}