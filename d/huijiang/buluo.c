// Room: /d/huijiang/buluo.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "�ز�����");
	set("long", @LONG
�˴����������֣�һ���б���£���һ���ޱߵĲ�ԭ��Զ����ɽ��
���������֣����������֦ͷ���С�б�µ�������ϴ�һƬ�յأ�����
��������ڿյص����롣
LONG
	);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"shulin",
		"west"  : __DIR__"shulin1",
		"south" : __DIR__"shulin2",
		"north" : __DIR__"buluo1",
	]));

	set("no_clean_up", 0);
	set("coor/x", -50050);
	set("coor/y", 9040);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
