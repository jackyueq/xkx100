// Room: /d/lingxiao/liang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","����");
	set("long",@LONG
�������Խ��ķ��䣬�����Ե������������������෴������С����
������������ϰ�䣬����ѩɽҲδ�¹�һ�������������书���������
�У��ǽ����ڰ����ڵġ����ķ���������Ȼ������һ��һ��������֮�⣬
������� 
LONG);
	set("exits",([ /* sizeof() == 1 */
		"north" : __DIR__"zoulang3", 
	]));
	set("objects", ([
		__DIR__"npc/liang" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

