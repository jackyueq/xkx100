// Room: /d/xingxiu/xxhb2.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "���޺�");
	set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ���ն�
����ͨ�����޺������
LONG );
	set("objects", ([
		__DIR__"npc/haoshou" : 1,
	]) );
	set("exits", ([
		"southeast" : __DIR__"riyuedong1",
		"northeast" : __DIR__"xxhb3",
		"west"      : __DIR__"xxhb4",
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -50010);
	set("coor/y", 20400);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);

}
