// Room: /d/songshan/westwuchang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "���䳡");
	set("long", @LONG
��������ɽ�ɵ����䳡���������û���������ɰʯ��ʵ�ģ�������
�ܽ�ʵ�����ӡ����䳡�м䰲��Щ��е�������������õġ�һЩ��ɽ��
������ͷ�����ؿ̿�������
LONG );
	set("outdoors", "songshan");
	set("exits", ([
		"east"  : __DIR__"westpath3",
		"south" : __DIR__"westpath2",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", -40);
	set("coor/y", 920);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
