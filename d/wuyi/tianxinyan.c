// Room: /d/wuyi/tianxinyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������������ɽ������������ɽ־���أ���ȫɽ�ٶ�ʮ���֮����
������룬����֮�༫Ҳ����Ի���ġ���
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"yonglechansi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1410);
	set("coor/y", -4930);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

