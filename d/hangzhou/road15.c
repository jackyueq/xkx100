// road15.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�������������
�������������߸���һ����������ϱ��������ɽ��ɽ·��
LONG);
        set("exits", ([
            "northeast" : __DIR__"road14",
            "southwest" : __DIR__"yuhuangsj",
            "west"      : __DIR__"road16",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xihu");
	set("coor/x", 4130);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
