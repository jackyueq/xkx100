// Room: /d/kunlun/cemen.c
// Last Modified by winder on Nov. 15 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�ƹ���ʥ�õĺ�԰������һ���������۵Ļ������ִ����������
֮�С������������࣬�Ż����������������ɵĲ��š�
LONG );
	set("exits", ([
//		"west"  : __DIR__"klshanlu1",
//		"north" : __DIR__"westxiangfang",
		"east"  : __DIR__"huayuan",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119991);
	set("coor/y", 40130);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}