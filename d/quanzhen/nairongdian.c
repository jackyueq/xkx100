// nairongdian.c ���ݵ�
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���ݵ�");
        set("long", @LONG
�����Ǵ����Աߵ�һ����Ҳ�ǽӴ���Ҫ���˵ĵط����
��ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ����ɽ��������
����ǽ���Ϲ���һЩ�ֻ���
LONG
        );
        set("exits", ([
                "south" : __DIR__"qingjing",
                "west" : __DIR__"piandian",
                "north" : __DIR__"datang3",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/cheng" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -2780);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}