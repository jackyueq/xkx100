// Room: /d/huijiang/shamo1.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set ("short", "ɳĮ");
	set ("long", @LONG
����ɫ��ɳ�����࣬��������һƬ�������У����ϲ������񣬵���
�������ޡ�ֻ��ɳĮ�е��е�����ʬ�������㣬�����й������ĺۼ���
Զ��������һĨ���͡�
LONG);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __FILE__,
		"west"  : __FILE__,
		"south" : __FILE__,
		"north" : __DIR__"shamo2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", 9000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
