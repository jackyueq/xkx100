// Room: /d/nanshaolin/hguangc4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���㳡");
	set("long", @LONG
�����Ǻ��㳡�����������ʯ��ƴ�ɵĵ������м�����͹��̤�ۣ�
������ǰ�и���ʩչ�ڹ���������ӡ�ǣ������Ǻ�
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"east" : __DIR__ "houdian",
		"south" : __DIR__ "hguangc1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

