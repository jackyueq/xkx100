// Room: /d/nanshaolin/fxjing.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIY"���ľ�"NOR);
	set("long", @LONG
����һ��ǧ��ž�������������ʯ���ɵľ�̨������������������
��һ����һ�ߵľ�Ե���������ʮ���ף���������������ס����ڴ���
һ��ľ�Ƶ����������ˮ��
LONG );
	set("exits", ([
		"eastup" : __DIR__"ting",
	]));
        set("resource/water",1); 
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1810);
	set("coor/y", -6350);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
