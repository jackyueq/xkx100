// /d/taohua/liangongfang.c
#include <room.h>;
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����һ����ϵ������������а��ż��������ˣ��Ǹ��һ���������
���õġ����ﾭ���е������ڴ�����������Ĵ���������������һ�
�����Խ��塣
LONG );
	set("exits", ([
	    "south" :__DIR__"lianwuchang",
	    "north" :__DIR__"siguoshi" ,
	]));
	set("objects", ([
	      __DIR__"npc/jiguan" : 5,
	]) );
//	set("no_clean_up", 0);
	set("coor/x", 8980);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}