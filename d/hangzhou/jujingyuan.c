// jujingyuan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�۾�԰");
        set("long", @LONG
����԰�У�ֻ���������ô������������У����˲��ٱ��ҡ�����
��ů֮ʱ���������ǧ������˿�����̽��벻ʤ������ʫ��������
�ġ��Һ���׽Կ�ã���ô����෢�ӡ����ݵ�ǡ���ô�����������
���ţ����������������š�
LONG);
        set("exits", ([
            "east"      : __DIR__"qingbomen",
            "northeast" : __DIR__"liulangqiao",
        ]));
        set("objects", ([
            __DIR__"npc/jian-ke" : 1,
            __DIR__"npc/honghua2" : 1,
        ]));
        set("outdoors", "xihu");
//        set("no_clean_up", 0);
	set("coor/x", 4120);
	set("coor/y", -1490);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
