// /beijing/hai_dayuan.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","���ι�����Ժ");
	set("long", @LONG
���ǽ��ź��һ������Ļ�԰��������һ���᷿��������һ������
��ͨ�����ι����Ļ����������Ǻ��ι����Ĵ��ţ�������Ǵ����ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"hai_men",
		"south" : __DIR__"hai_dating",
		"east" : __DIR__"hai_huating",
		"west" : __DIR__"hai_fang",
	]));
	set("objects", ([
		__DIR__"npc/shiwei1" : 1,
		__DIR__"npc/shiwei2" : 1,
	]));

	set("outdoors", "beijing");
	set("coor/x", -230);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
