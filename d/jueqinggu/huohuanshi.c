// Room: /d/jueqinggu/huohuanshi.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����ש�ߵĴ�Ҥ��Խ��ש�ڣ����ȸ�ʢ�������ֹ����ڰ��
��̿����������ಲ������ֻ��һ��ţͷ�̿㣬أ��ȫ������졣
LONG
	);

	set("exits", ([
		"west" : __DIR__"huilang1",
		"enter" : __DIR__"huohuanshi1",
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

