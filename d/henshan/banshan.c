// Room: /d/henshan/banshan.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ɽͤ");
        set("long", @LONG
���ڵ��˰�ɽͤ�������뵽ף�ڷ����۸̻߳����г̣���ǡ����һ
��֮����·��Сͤ��Ȼ�Ѽ��žã�����Ϊ���������ڷ���ꡣ
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shanlu4",
           "northup"    : __DIR__"shanlu5",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "henshan");
	set("coor/x", -320);
	set("coor/y", -1050);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
