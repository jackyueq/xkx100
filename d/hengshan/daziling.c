// Room: /d/hengshan/daziling.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�����������ɽ����֮·��ʯ�������� "����" ���֣��߿����ɣ�
�����پ��������ۻ롣
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"west"      : __DIR__"yunge",
		"northeast" : __DIR__"hufengkou",
	]));
	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 3140);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

