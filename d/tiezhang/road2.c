// Room: /d/tiezhang/road2.c
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
		"west"      : __DIR__"road3",
		"northeast" : __DIR__"road1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2020);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}