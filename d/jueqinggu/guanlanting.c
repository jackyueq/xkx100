// Room: /d/jueqinggu/guanlanting.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>;
inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����ͤ���Ľ�߬�ⶥ���ܽǷ��̣��������У���׾���־��ɡ�ɽ��
����ˮ�����ƣ�ˮ��������ͤ����ɽʯ������ǧ�ʰ�̬������ͤ�п���
�̲��������������ٺ�����֮�С�
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"dufengling",
		"northup"   : __DIR__"xiangqinxie",
		"east"      : __DIR__"meiyupu",
	]));

	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -480);
	set("coor/y", -380);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

