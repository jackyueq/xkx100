// Room: /d/quanzhou/cangjingge.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�ؾ���");
	set("long", @LONG
�ؾ����ǿ�Ԫ�µ���ߴ�������һ��Сɽ���ϡ�������㣬������
һС�Ž��ա��Ǹ�ƾ������˫����գ���̳���أ��ĸ�ʫ�⡣���ϲؾ�
�����
LONG );
	set("exits", ([
		"southdown" : __DIR__"jietang",
		"northdown" : __DIR__"houshanmen",
	]));
	set("objects", ([
		__DIR__"npc/sengren" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6470);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
