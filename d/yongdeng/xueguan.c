// Room: /huanghe/xueguan.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "ѧ��");
	set("long", @LONG
һ���ª��˽�ӣ��ıڽԿգ������а�����ѧ�����Լ�����̧����
���������ʡ�һ���鰸�������ӵ�һͷ�����ϰ��ż��������˵ġ�����
���������ټ��ա���һ�ѽ�ߡ���ʥ��ʦ���Ϸ��ӵ�ʯ����Ƭ��������
���鰸�����档
LONG );
	set("exits", ([
		"south"    : __DIR__"gulang",
	]));
	set("objects", ([
		__DIR__"npc/xiucai" : 1,
	]));
	set("coor/x", -9600);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}