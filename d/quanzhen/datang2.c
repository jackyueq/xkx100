// datang2.c ���ö���
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���ö���");
        set("long", @LONG
�����Ǵ��õĵڶ��أ���ȫ��̵��������ε����ڡ����ڻ�����
����ʱ�䣬������յ����ģ�ֻ��ȫ����ƹ��������µ����������
���ż���С��ͯ���������Σ�Ԥ���ͷ���
LONG
        );
        set("exits", ([
                "east" : __DIR__"datang3",
                "west" : __DIR__"datang1",
                "north" : __DIR__"cetang",
                "south" : __DIR__"piandian",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/zhangli" : 1,
                __DIR__"npc/daotong1" : 1,
        ]));
	set("coor/x", -2790);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}