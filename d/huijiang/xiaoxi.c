// Room: /d/huijiang/xiaoxi.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set ("short", "СϪ��");
	set ("long", @LONG
�ڲ�̽������ʯ֮�����ʵ�һ��СϪ�����峺�ĺӵ��ǹ⻬�Ķ�
��ʯ�����ʵ�Ϫˮ΢΢����������Ϫˮ������С���������ײ��������
����������������ˣ��������֡�
LONG);
	set("exits", ([ /* sizeof() == 2 */
		"northup" : __DIR__"xiaoxi1",
		"east"    : __DIR__"gebi2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huijiang");
	set("coor/x", -50020);
	set("coor/y", 9000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
