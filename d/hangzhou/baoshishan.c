// baoshishan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯɽ");
        set("long", @LONG
��ʯɽ���Ǻܸߣ�ɽ�϶�����ʯ�����иߴ��߾��ǡ���ʼ����
��ʯ����ɽ·����һ��ͤ�ӡ�����ͤ����ͤǰ�п����δ�ʯ���ٿո�
����ɽ�ۣ�������ʯ���ֳ�����ʯ���������Ͼ͵��˱�������������
��ص�����ˡ�
LONG);
        set("exits", ([
            "northup"   : __DIR__"baoshuta",
            "southdown" : __DIR__"road8",
        ]));
        set("objects", ([
            __DIR__"obj/shitou": 1,
            __DIR__"obj/eluanshi": 1,
        ]));
        set("outdoors", "xihu");
//        set("no_clean_up", 0);
	set("coor/x", 4100);
	set("coor/y", -1430);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
