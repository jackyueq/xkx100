// room: /d/xingxiu/tianroad1.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "��ɽɽ·");
	set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ
��ԭ����ԭ��һλ�����˸���һȺ�������򶫿�����ɽ�����ߴ�����
�����޵�Х����
LONG );
	set("outdoors", "xiyu");
	set("exits", ([
		"eastdown" : __DIR__"shanjiao",
		"north"    : __DIR__"tianroad2",
	]));
	set("objects", ([
		__DIR__"npc/herdsman" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", 10000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
