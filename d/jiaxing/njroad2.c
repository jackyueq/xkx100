// Room: /d/jiaxing/njroad2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ�����е�С·��·����һ���񷿣����������Ѿ��ܾúܾ�û����
ס�ˡ�
LONG
	);
	set("outdoors","jiaxing");

	set("exits", ([
		"west" : __DIR__"njroad1",
		"east" : __DIR__"njroad3",
		"north": __DIR__"guojia",
	]) );
	set("objects", ([
		"/d/village/npc/girl" : 1,
	]) );

	set("coor/x", 1570);
	set("coor/y", -1050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}