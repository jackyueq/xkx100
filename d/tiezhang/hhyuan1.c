// Room: /d/tiezhang/hhyuan1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����һ���������ŵĻ�԰��ֻ���������񣬲Դ���죬������ᶣ�
������������һ����ɽ��������һ��Ƭ�Ļ��ԡ�������ͨ��ɽ�ϵ�
·��
LONG	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"shanlu3",
		"south" : __DIR__"hxfang",
		"east"  : __DIR__"hhyuan2",
		"west"  : __DIR__"hhyuan3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2040);
	set("coor/y", -1940);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}