// Room: /d/mobei/caoyuan5.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "�ɹŲ�ԭ");
	set("long", @LONG
���ƴ��������տ��ٵ��ƶ��������������������ڲ�ס��������
���¾��ǹ�����ɹŲ�ԭ��Զ��������������һƬ�����Ӫ�ʣ��Ǿ���
��ľ��Ĳ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"caoyuan6",
		"south"     : __DIR__"caoyuan4",
	]));
	set("coor/x", -230);
	set("coor/y", 5190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
