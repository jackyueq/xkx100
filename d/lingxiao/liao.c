// Room: /d/lingxiao/liao.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","����");
	set("long",@LONG 
�����������ķ��䡣��λ�����У�������Ϊ���Զ��ǣ�����˵����
�ǵ�����ʦ��ȥʱ���������������ڣ�����������֮ʱ������Ѷ�����
������֮λ��Ϊ������֮��ⷿ���ڰ������飬�ӡ����ӱ���������
ʷ�ǡ���������Ȩı����֮�顣
LONG);
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"zoulang3", 
	]));
	set("objects", ([  
		__DIR__"npc/liao" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8830);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

