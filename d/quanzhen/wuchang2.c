// wuchang2.c �䳡
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�䳡");
        set("long", @LONG
������ȫ��̵����䳡�����µ���ש�����̵��������룬ȴ
��֪����˭�ȳ��˼�ʮ�����СС�İ��ӡ����ĳ������������
���µ��е��������Ʒ��������쳤�վã����¾Ͳȳ��˰��ӡ���
���������ż��������õ�ľ�ˡ�
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "north" : __DIR__"wuchang1",
                "east" : __DIR__"xiuxishi",
                "southeast" : __DIR__"shantang",
        ]));

        set("objects", ([
                "/d/shaolin/npc/mu-ren" : 4,
        ]));

	set("coor/x", -2750);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}