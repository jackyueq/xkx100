// /beijing/hai_dating.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","���ι�������");
	set("long", @LONG
���Ǻ��ι����Ĵ�������������װ��Ҳ�������������������ﾹ
Ȼ��һ�ȹ����ľ�������ʱ��������һƬ���ӣ�������������Ѱ�µ���
ǰ������
LONG );
	set("exits", ([
		"north" : __DIR__"hai_dayuan",
		"south" : __DIR__"hai_houyuan",
	]));
	set("objects", ([
		__DIR__"npc/zheng" : 1,
		__DIR__"npc/feng" : 1,
		__DIR__"npc/duolong" : 1,
	]));

	set("coor/x", -230);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
