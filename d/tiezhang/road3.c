// Room: /d/tiezhang/road3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ǵ�
�潻�磬��˵���������˳�û�����ɾ�����
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"northwest" : __DIR__"shanjiao",
		"east"      : __DIR__"road2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2030);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}