// Room: /d/taiwan/zhuluo.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ޣ�λ�ڰ���ɽɽ´ԭΪƽ������¤��۾�֮�أ����������ʼ
�𽥷�չ�ɶ��������ǰ���ɽ��ҵ��ľ�ļ�ɢ�����Ʋļӹ����ġ� 
LONG );
	set("exits", ([
		"northwest" : __DIR__"pingye",
		"southwest" : __DIR__"zhenbeifang",
	]));
	set("objects", ([
		__DIR__"npc/qiaofu": 1,
		__DIR__"npc/shangren": 1,
		__DIR__"npc/pingpuren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2520);
	set("coor/y", -7030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

