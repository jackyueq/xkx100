// Room: /d/tiezhang/shijie3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
һ��ʯ���������£���ʧ��ŨŨ�ĺڰ��С�ʯ���ϳ�������ɫ����
̦���������š�Զ���ڰ��ľ�ͷ�ƺ��е��ƵĹ�����
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"shishi",
		"southup"  : __DIR__"shijie2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", 1870);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}