// huagang.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���۹���");
        set("long", @LONG
ֻ��������һС����һ�����ź����档��������Ⱥ����������
Ͷ�������º��㣬��ʳ������л������԰ʱ����ʫһ�ס����Ⱥ����
���࣬����ž��ҷ��㡣��թ������������������˿��˺�����
LONG);
        set("exits", ([
            "east"     : __DIR__"suti6",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/baizhi" : random(2),
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4100);
	set("coor/y", -1440);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
