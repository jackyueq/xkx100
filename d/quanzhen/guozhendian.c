// guozhendian.c �����
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����Ǵ����Աߵ�һ����Ҳ�ǽӴ���Ҫ���˵ĵط����
��ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ����ɽ��������
����ǽ���Ϲ���һЩ�ֻ���������������������һ���Ĳ��С����
LONG
        );
        set("exits", ([
                "west"  : __DIR__"cetang",
                "south" : __DIR__"datang3",
                "north" : __DIR__"cundaota1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2780);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}