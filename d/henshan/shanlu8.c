// Room: /d/henshan/shanlu8.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣�ϱ߾��Ǹ����¡�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southup"  : __DIR__"fuyansi",
           "northup"  : __DIR__"mojingtai",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -1060);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
