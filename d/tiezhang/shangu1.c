// Room: /d/tiezhang/shangu1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ����խ��ɽ��֮�У�����ɽ�������ֱ������������Գ��
֮�����ص��ڼž��Ŀչ�֮�С�
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"shangu2",
		"southwest" : __DIR__"pingtai",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2030);
	set("coor/y", -1900);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

