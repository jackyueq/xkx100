// Room: /d/henshan/liuyunping.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����ƺ");
        set("long", @LONG
ÿ���������ں�ɽ������������������ɽ����ӿ��������ɽ����
��ǰɽ��к��ֱ�����ӷ�к��εΪ׳�ۣ�����������ŵ������澰��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westdown"  : __DIR__"nantian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -1020);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
