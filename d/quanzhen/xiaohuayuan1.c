// xiaohuayuan1.c С��԰
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "С��԰");
        set("long", @LONG
���������������С��԰��������Ʈ��һ���ʻ�����ζ������
��ȥ�����ǽ�����ˡ������԰����ȴ��ȫ�����������϶�
������ĵط���԰�м�����һ���Ӳݣ�Ҳ��ר�����˸���������
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "southwest" : __DIR__"houtang3",
                "northeast" : __DIR__"xiaohuayuan2",
        ]));

        set("objects", ([
                CLASS_D("quanzhen")+"/zhangyuan" : 1,
        ]));

	set("coor/x", -2730);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}