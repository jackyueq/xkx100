// houtang3.c ��������
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������ȫ��̵��������书�ĵط���ȫ��̵����ڶ࣬����ÿ��
ÿ�µ�ʮ�����죬���ټ����е����������д��书��һ����������
�ǵ��书��������һ����ѡ���˲ŵ��ν��е���Ҫְ�����ڻ�����
��������ӣ����п���һ�ˡ�
LONG
        );
//        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"jingxiushi",
                "west" : __DIR__"houtang2",
                "northeast" : __DIR__"xiaohuayuan1",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/wangzhitan" : 1,
        ]));

	set("coor/x", -2740);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}