// xiaohuayuan2.c С��԰
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "С��԰");
        set("long", @LONG
���������������С��԰����ֲ��һЩ�в����������Ļ�ľ��
԰������һ����ɽ����ɽ����һ̶СС�Ľ���أ���ˮ�峺���ף�
�㿴����������ɫ�Ľ����������������յ�������ȥ��������ͯ��
��������Ϸ�š�
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "east" : __DIR__"xiaohuayuan3",
                "west" : __DIR__"chanfang3",
                "southwest" : __DIR__"xiaohuayuan1",
        ]));
        set("objects", ([
                __DIR__"npc/daotong" : random(3),
        ]));

	set("coor/x", -2720);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}