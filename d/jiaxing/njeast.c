// Room: /d/taohua/njeast.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ţ�Ҵ��");
	set("long", @LONG
����һ��С����Ķ���ڡ����Ӻ�С��������һƬ�ž��С��ϱ���
Լ���Կ���һ���󽭡�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");
	set("exits", ([
		"west": __DIR__"njroad3",
	]) );
	set("objects", ([
		"/d/village/npc/kid" : 1,
	]) );

	set("coor/x", 1590);
	set("coor/y", -1050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}