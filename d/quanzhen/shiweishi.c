// shiweishi.c ��Ϊ��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ϊ��");
        set("long", @LONG
������ȫ������֮�����ڵľ��ҡ������С��ֻ�ڷ���һ�Ŵ���
һ��������һ�����ӡ������Ϸ���һ�������ӡ���ֻ����һ�룬����
�����۵����������롣
LONG
        );
        set("exits", ([
                "south" : __DIR__"cetang",
        ]));

        set("objects", ([
                CLASS_D("quanzhen")+"/ma" : 1,
        ]));
	set("coor/x", -2790);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}