// qingbomen.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�岨��");
        set("long", @LONG
԰�ſ���һ����¥�������Ͽ��š��岨�š�����¥��վ�ż�����
�ҹ�������Ů������׹����ۡ��������ͽ��˾۾�԰��������ص���
·��
LONG);
        set("exits", ([
            "east"   : __DIR__"road14",
            "west"   : __DIR__"jujingyuan",
        ]));
        set("objects", ([
            __DIR__"npc/girl" : 2,
        ]));
        set("outdoors", "xihu");
//        set("no_clean_up", 0);
	set("coor/x", 4130);
	set("coor/y", -1490);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
