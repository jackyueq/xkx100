// Room: /d/tiezhang/sslu3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
������һ������ʯ�̳ɵ�С·�ϡ�����ɽ�Ƶͻ��������˴��̵�ë
������΢�紵�������Ա�����һƬɳɳ����
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"sslu2",
		"northup"  : __DIR__"mzfeng",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2010);
	set("coor/y", -1910);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}