// Room: /d/yanziwu/path11.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
һ������С������������ǰ����ֻ��С�����࣬��ľ���裬������
�ʮ���徻��ǰ�濴����ͤԺ���󲻼�¥��Ψ�����������ڵ͵�
������
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"south"  : __DIR__"bridge1",
		"north"  : __DIR__"mingzhu",
		"east"   : __DIR__"path12",
		"west"   : __DIR__"bridge2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoshi" : 1,
	]));
	set("coor/x", 1240);
	set("coor/y", -1220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}