// Room: /huanghe/yongdeng.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������������ľ����������ǡ�һ���³�������ãã��Ұ֮�ϡ���
�ǽ��ں�������䣬���Ŵ󽫾���ȥ�����ڴ��������꣬��һ��ƽ����
�������������������ﶼ�о��ӳ�פ��
LONG );
	set("exits", ([
		"southup" : "/d/xingxiu/xxroad3",
		"north"   : __DIR__"gulang",
		"southeast"    : "/d/huanghe/huanghe_3",
		"west"    : __DIR__"kedian",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 4,
	]));
	set("outdoors", "yongdeng");
	set("coor/x", -9600);
	set("coor/y", 3100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}