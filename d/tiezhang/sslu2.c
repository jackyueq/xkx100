// Room: /d/tiezhang/sslu2.c
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
		"eastup"   : __DIR__"sslu3",
		"westdown" : __DIR__"sslu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2020);
	set("coor/y", -1910);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}