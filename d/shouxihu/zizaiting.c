// Room: /yangzhou/zizaiting.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������ͤ");
	set("long",@LONG
���Ҷ��Ϻ����ߣ���������ͤһ�����ֹ�ַ����Ϊ��������ͤ����
����ʯ����ʯ�ʣ��Թ�ˮ����
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"northwest"  : __DIR__"qinshi1",
	]));
	set("objects", ([
		"/d/city/npc/lady2" : 1,
	]));
	set("coor/x", 30);
	set("coor/y", 90);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
