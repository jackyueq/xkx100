// Room: /d/lingxiao/zhongting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","��ͥ");
	set("long",@LONG 
�����������ǵ���ͥ�����Ҷ����������ӵ�ס���������ڶ������
Ҫ��������������������ƽʱ������ϰ���⣬����֮ʱ�������ڷ�����
������ȭ�ף���������и���� 
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"zoulang1",
		"east"  : __DIR__"zoulang2",
		"north" : __DIR__"houyuan1",  
		"south" : __DIR__"qianyuan", 
	]));	
	set("objects",([
		__DIR__"npc/bao" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8870);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

