// wuchang1.c �䳡
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�䳡");
        set("long", @LONG
������ȫ��̵����䳡�����µ���ש�����̵��������룬ȴ
��֪����˭�ȳ��˼�ʮ�����СС�İ��ӡ����ĳ������������
���µ��е��������Ʒ��������쳤�վã����¾Ͳȳ��˰��ӡ�
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "south" : __DIR__"wuchang2",
                "north" : __DIR__"houtang2",
                "southeast" : __DIR__"xiuxishi",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2750);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}