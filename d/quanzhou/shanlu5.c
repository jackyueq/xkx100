// Room: /d/quanzhou/shanlu5.c
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
		"south"   : __DIR__"shanlu6",
		"northup" : __DIR__"cienyan",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu" : 1,
	]));
	set("coor/x", 1850);
	set("coor/y", -6470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
