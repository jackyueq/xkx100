// Room: /d/quanzhou/shanlu3.c
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
		"southup" : __DIR__"ruixiangyan",
		"northup" : __DIR__"shanlu2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1850);
	set("coor/y", -6420);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
