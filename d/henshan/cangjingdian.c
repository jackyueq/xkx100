// Room: /d/henshan/cangjingdian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
�ؾ������������£������̫������ "��ؾ�" �����������ľ
���죬����Ʈ���滨��ݣ����������ɫ������ "�ؾ���֮��" ��
��ɽ���ľ�֮һ��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "east"   : __DIR__"shanlu14",
           "south"  : __DIR__"shuzhuangtai",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -340);
	set("coor/y", -1010);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
