// Room: /d/jueqinggu/huohuanshi1.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǽ����������ʯ�ң������ͺͺ�Ķ���ʯ�ڡ�ֻ��һ��С��
���΢���Ĺ������������ڣ������޷����ܡ�
LONG
	);

	set("exits", ([
		"out" : __DIR__"huohuanshi",
	]));
	set("objects", ([
		__DIR__"npc/puren" : 1,
	]));
	set("coor/x", -540);
	set("coor/y", -370);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

