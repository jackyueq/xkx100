// Room: /d/mobei/caoyuan4.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "�ɹŲ�ԭ");
	set ("long", @LONG
���ƴ��������տ��ٵ��ƶ��������������������ڲ�ס��������
���¾��ǹ�����ɹŲ�ԭ��Զ��������������һƬ�����Ӫ�ʣ��Ǿ���
��ľ��Ĳ��䡣
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"caoyuan5",
		"south" : __DIR__"caoyuan",
	]));
	set("coor/x", -230);
	set("coor/y", 5180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
