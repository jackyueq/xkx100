// Room: /d/quanzhou/shanlu1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������Դɽ������ʯС�����������ѣ�������ľïʢ��������ա�
������Ҷ������ϡ�ɡ������ౡ�����ϰϰ��
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"southup"   : __DIR__"qingyuandong",
		"northdown" : __DIR__"anpingqiao",
	]));
	set("objects", ([
		__DIR__"npc/banjiu" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
