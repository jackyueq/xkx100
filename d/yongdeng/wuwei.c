// Room: /huanghe/wuwei.c
// Java Sep. 22 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ĺ�����������פ���ر�����¥�ߴ����ɣ��ſ�������
�ٱ�����������̲�������ˣ����ſڵĸ�ʾ�ϻ������ͨ���Ľ����
����ͼ�Σ�����ͷ����ȥ��ͦ���֡����Ͼ���ȥ���ǵķ����ˣ�������
��������ɽ����
LONG );
	set("exits", ([
		"southeast" : __DIR__"wuqiao",
		"north"     : __DIR__"tumenzi",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" : 3,
	]));
	set("outdoors", "yongdeng");
	set("coor/x", -23000);
	set("coor/y", 8000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}