// Room: /d/taiwan/yahoushe.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�ź���");
	set("long", @LONG
�ź����ֳư����磬�˵�����������ƽ��������֧�尢����֮��
�����롣������ԭ�����ڴ��磬��δ���ʱ��������ѣ�ֻ����
�ض�Ǩ�����н��磬��Ϊ�ź��硣
LONG );
	set("exits", ([
		"west" : __DIR__"dagougang",
	]));
	set("objects", ([
		__DIR__"npc/makadaoman": 1,
		__DIR__"npc/makadaowoman": 1,
		__DIR__"npc/makadaokid": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2520);
	set("coor/y", -7070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

