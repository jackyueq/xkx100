// suti2.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
�յ��ϣ��ο����е���������������ʫ����̸���ۣ��е����
��ʯ����ˮ�������е��������ߣ���������������ǿ���ţ�������
�����ţ�������ȥ��Ժ��ɡ�
LONG);
        set("exits", ([
            "north"     : __DIR__"suti1",
            "south"     : __DIR__"suti3",
            "west"      : __DIR__"quyuanbei",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/heye" : random(2),
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4080);
	set("coor/y", -1460);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
