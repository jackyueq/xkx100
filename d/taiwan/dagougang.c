// Room: /d/taiwan/dagougang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�򹷸�");
	set("long", @LONG
�򹷸�Ҳ�ơ����ۡ��������С�������е����������ھ�����Ͽ
�壬��ǫ̈̄��һ���ۡ�����������������ͱ��ڴ˿������ܡ�������̨
�󣬴򹷸۵���ҵ�������ó�������ʢ�����½�������Ƶ������
����Ϊ̨���������������ͣ���ۡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"yahoushe",
		"north" : __DIR__"ningnanfang",
	]));
	set("objects", ([
		__DIR__"npc/yufu": 1,
		__DIR__"npc/shangren": 1,
//		__DIR__"npc/pingpuren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2510);
	set("coor/y", -7070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

