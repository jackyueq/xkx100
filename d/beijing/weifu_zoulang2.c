// /beijing/weifu_zoulang2.c
// Last modified by winder 2003.10.10

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "Τ������");
	set("long", @LONG
����һ��ľ�Ƶ����ȣ�������ǹ⻬����������һ����Ⱦ������Τ
���������ڴ��߶����ϱ��Ǹ��޴�Ļ�԰�����߾���Τ���Ĵ�����
LONG );
	set("exits", ([
		"north" : __DIR__"weifu_dating",
		"south" : __DIR__"weifu_dayuan",
	]));

	set("outdoors", "beijing");
	set("coor/x", -220);
	set("coor/y", 4120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
