// Room: /d/jueqinggu/songtang.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ǰһ�����䳯���İ�ʯ���������й��ӵļ�ɽ��ʯ�����ܱ�ֲ��
Ƥ�ɣ������Ǿ��ڣ�ֻ�����������׶���ִ������վ����ǰ��
LONG
	);

	set("exits", ([
		"east"    : __DIR__"huacong11",
		"northup" : __DIR__"shanlu1",
		"westup"  : __DIR__"sanqingxuan",
		"south"   : __DIR__"qingzhiyuan",
	]));
	set("objects", ([
		__DIR__"npc/boy" : 2,
	]));

	set("outdoors","jueqinggu");
	set("coor/x", -530);
	set("coor/y", -360);
	set("coor/z", 10);
	setup();
	replace_program(ROOM); 
}

