// Room: /wuliang/jianhugong.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������߾ӽ���֮�࣬���Ž�����ңң����������ڡ���������
�����������ճ����֮����
LONG );
	set("exits", ([
		"southdown"  : __DIR__"road4",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("coor/x", -71000);
	set("coor/y", -79870);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}