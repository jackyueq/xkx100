// yuquan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ȫ");
        set("long", @LONG
��Ȫ�½�����Ȫɽ�ϣ�ԭ�������¡��߽���Ȫ�£�ֻ�������м���ˮ��(pond)��
�������ǳ�����ɽ��·��
LONG);
        set("exits", ([
            "eastdown"  : __DIR__"road5",
        ]));
        set("item_desc", ([
            "pond":
"���Ե�ʯ�����š�������Ȫ��������ż��Сˮ����ӿ������һ������\n",
        ]));
        set("objects" , ([
            __DIR__"npc/you-ke" :1,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4060);
	set("coor/y", -1440);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
