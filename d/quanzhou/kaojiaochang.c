// Room: /d/quanzhou/kaojiaochang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���̳�");
	set("long", @LONG
��������ݵĿ��̳�������������������ӵ��ڴ�ϰ�䣬ȭ��
���ߣ��赶Ū����ˣǹ�Ӱ��ĺò����֡��������̳�������ݵ�ǰ����
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"east" : __DIR__"wuguangate",
		"west" : __DIR__"dating",
	]));
	set("objects", ([
		__DIR__"npc/xuetu" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
