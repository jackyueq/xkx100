// chanfang2.c ����
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ȫ������������ԡ��������ĵط���Ϊ�˷�����������
�ζ�û�аڷţ������ڵ��¶��˼���С���š�
LONG
        );
        set("exits", ([
                "east" : __DIR__"chanfang3",
                "west" : __DIR__"chanfang1",
                "south" : __DIR__"liangong",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2740);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}