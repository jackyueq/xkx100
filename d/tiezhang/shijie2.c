// Room: /d/tiezhang/shijie2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
һ��ʯ���������£���ʧ��ŨŨ�ĺڰ��С�ʯ���ϳ�������ɫ����
̦���������š�Զ���ڰ��ľ�ͷ�ƺ��е��ƵĹ�����
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"westup"    : __DIR__"shijie1",
		"northdown" : __DIR__"shijie3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", 1860);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

