// baoshuta.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������̬����ͦ�Σ�������С��ȴ�����˼��ߵ�������˵��
Խ��Ǯ��������뾩������δ������������ˬΪףԭ��ƽ��������
������������������������������ɽ��·��
LONG);
        set("exits", ([
            "southdown" : __DIR__"baoshishan",
        ]));
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4100);
	set("coor/y", -1420);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
