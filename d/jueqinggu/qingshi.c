// Room: /d/jueqinggu/qingshi.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǹ���ֹ��˯��������Ĵ�����޳�У�����վ��һ��Ѿ�ߣ���
���뿪�����ڹ��߲�̫������
LONG
	);

	set("exits", ([
		"south" : __DIR__"huilang1",
	]));
	set("objects", ([
		__DIR__"npc/yahuan" : 1,
	]));
	set("coor/x", -550);
	set("coor/y", -360);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

