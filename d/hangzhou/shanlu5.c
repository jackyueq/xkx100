// shanlu5.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����С·�ϣ�ֻ����ɽ��Ұ���������͵Ĳ��ũ����Ů���ڻ�
Ц���вɲ衣ɽ·�����������ߣ����߾�����������������һ����
·��
LONG);
        set("exits", ([
                "westup"   : __DIR__"shanlu4",
                "northeast": __DIR__"tulu1",
                "north"    : __DIR__"longjing",
                "east"     : __DIR__"yanxiadong",
        ]));
        set("objects", ([
                __DIR__"npc/caichanu" :2,
        ]));
        set("outdoors", "hangzhou");
	set("coor/x", 2620);
	set("coor/y", -1600);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
