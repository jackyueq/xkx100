// Room: /d/henshan/zhongting.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ͤ");
        set("long", @LONG
��ͤ��������һ�ڣ��ؾ�ǧ�ÿ��ɽ�鱩����������飬����ʾ
�������Ŷ�ʮ���⡣ 
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "west"   : __DIR__"kuixingge",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -290);
	set("coor/y", -1180);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
