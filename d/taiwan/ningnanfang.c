// Room: /d/taiwan/ningnanfang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "���Ϸ�");
	set("long", @LONG
֣����̨ʱ����̨�帮�Գ�Ƕһ��Ϊ���ģ����нֻ���Ϊ�ķ���̨
�������Ա���֣������֮�ķ������Ϸ��˳�Ƕ���ϲ�һ����
LONG );
	set("exits", ([
		"north" : __DIR__"chiqian",
		"south": __DIR__"dagougang",
	]));
	set("objects", ([
		__DIR__"npc/bing": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2510);
	set("coor/y", -7060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

