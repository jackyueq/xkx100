// Room: /d/taiwan/donganfang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
֣����̨ʱ����̨�帮�Գ�Ƕһ��Ϊ���ģ����нֻ���Ϊ�ķ���̨
�������Ա���֣������֮�ķ����������˳�Ƕ�Ƕ���һ����
LONG );
	set("exits", ([
		"west" : __DIR__"chiqian",
	]));
	set("objects", ([
		__DIR__"npc/bing": 1,
//		__DIR__"npc/shangren": 1,
//		__DIR__"npc/pingpuren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2520);
	set("coor/y", -7050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

