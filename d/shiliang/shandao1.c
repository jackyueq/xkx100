// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ����᫲�ƽ��ɽ�����˼���������˵���ﲻ�Ǻ�̫ƽ��
LONG
	);
	set("outdoors", "shiliang");
	set("exits", ([
		"southeast" : "/d/jiaxing/chating",
		"northup"   : __DIR__"shandao2",
	]));
	set("objects", ([
		__DIR__"npc/li" : 1,
	]));
	set("coor/x", 1590);
	set("coor/y", -1990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}