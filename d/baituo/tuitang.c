// Room: /d/baituo/tuitang.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ò���ֻ���������輸�����������ֻ������ߵ����ӹ���
������������������ʲô�����߸��������ƺ��Ǹ�СԺ�ӡ���������һ
����԰�ˡ�
LONG);
	set("exits", ([
		"south" : __DIR__"tangwu",
		"north" : __DIR__"huayuan",
		"west"  : __DIR__"danfang",
		"east"  : __DIR__"yuanzi",
	]));
	set("objects", ([
		__DIR__"npc/jiren1" : 2,
	]));
	set("coor/x", -50010);
	set("coor/y", 20055);
	set("coor/z", 30);
	setup(); 
	replace_program(ROOM);
}
