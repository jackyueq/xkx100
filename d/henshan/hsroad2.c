// Room: /d/henshan/hsroad2.c ����·
// Modified by Java on Feb.14 1998

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡�
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"northwest" : __DIR__"hsroad1",
		"southwest" : __DIR__"hsroad3",
		"southeast" : "/d/yanping/gudao1",
		"northeast" : "/d/huangshan/shanmen",
	]));

	set("no_clean_up", 0);
	set("coor/x", 300);
	set("coor/y", -1100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
