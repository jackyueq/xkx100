// Room: /d/quanzhou/shanlu4.c
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
		"southup" : __DIR__"cienyan",
		"northup" : __DIR__"wangzhouting",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu" : 1,
	]));
	set("coor/x", 1850);
	set("coor/y", -6450);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
