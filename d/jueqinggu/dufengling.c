// Room: /d/jueqinggu/dufengling.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ɽ�������̧ͷ���죬ֻ��һ�ߡ�ɽ��ˮ�̣���ɫ������
�ģ�ֻ�����¼�����Ϣ������͸�����գ�Ϫ���оſ��ʯӭ����������
������һ�㣬��ס��ȥ·��
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"guanlanting",
		"southdown" : "/d/xiangyang/caodi1",
	]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -390);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

