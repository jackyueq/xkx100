// feilaifeng.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������������շ塣������ɽС�������ߣ�ֻ��Ϫ����ʯ�ڼ��
��һ��̻��¶�أ�ϲЦ���������շ��Ա���һ��������ΰ�Ķ�����
������������ɽ��·��С·���������������ߡ�
LONG);
        set("exits", ([
                "north"     : __DIR__"road1",
                "eastup"    : __DIR__"qinglindong",
                "westup"    : __DIR__"longhongdong",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
	set("coor/x", 2500);
	set("coor/y", -1600);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
