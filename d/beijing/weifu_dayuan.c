// /beijing/weifu_dayuan.c
// Last modified by winder 2003.10.10

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "Τ����Ժ");
	set("long", @LONG
����¹����������ǰ��һ�������Ĵ�Ժ����Ժ����ֲ�Ÿ��໨�ݣ�
��ɽˮ�أ���¥��̨���ǳ�������Ժ�ڴ�ɨ�÷ǳ��ɾ���Τ���������
�������У�������һ��ľ�����ȣ�ͨ�������Ĵ�����
LONG );
	set("exits", ([
		"south" : __DIR__"weifu_zoulang1",
		"north" : __DIR__"weifu_zoulang2",
	]));
	set("objects", ([
		__DIR__"npc/yuanding" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -220);
	set("coor/y", 4110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
