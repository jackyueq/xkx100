// Room: /d/quanzhou/shanlu6.c
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
		"south"   : __DIR__"weiyuanlou",
		"north"   : __DIR__"shanlu5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1850);
	set("coor/y", -6480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
