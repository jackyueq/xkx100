// Room: /d/henshan/dadian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
�������������������׵�֮�á����ṹΪ����Ъɽ��������
�߲������������ʮ���ߣ������߼䣬��ʯ����ʮ��������������ʮ��
��֮������������ʥ�۱���ׯ�ϡ�������֮��Ϊ��ɽС�ľ�֮һ�� 
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"yushulou",
           "north"  : __DIR__"houdian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1130);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
