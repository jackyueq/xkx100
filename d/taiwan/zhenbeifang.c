// Room: /d/taiwan/zhenbeifang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�򱱷�");
	set("long", @LONG
֣����̨ʱ����̨�帮�Գ�Ƕһ��Ϊ���ģ����нֻ���Ϊ�ķ���̨
�������Ա���֣������֮�ķ����򱱷��˳�Ƕ�Ǳ���һ����
LONG );
	set("exits", ([
		"northwest" : __DIR__"anping",
		"northeast" : __DIR__"zhuluo",
		"south"     : __DIR__"chiqian",
	]));
	set("objects", ([
		__DIR__"npc/bing": 1,
		__DIR__"npc/shangren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2510);
	set("coor/y", -7040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

