// quyuanbei.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ժ���");
        set("long", @LONG
���С���ţ�ӭ����һͤԺ���Ա�����ʯ�������⡰��Ժ��ɡ���
�����ǻ��յ̡�
LONG);
        set("exits", ([
            "east"     : __DIR__"suti2",
            "enter"    : __DIR__"quyuanfenghe",
        ]));
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4070);
	set("coor/y", -1460);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
