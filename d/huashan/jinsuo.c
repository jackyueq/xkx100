// jinsuo.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
������ɽ������һ������������һƬ�����أ������Ǹ������Ƶ���
�ڣ��м�һ����С��������һ�򵱹أ����Ī����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"southup"   : __DIR__"zhenyue",
		"northdown" : __DIR__"shangtianti",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -870);
	set("coor/y", 200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
