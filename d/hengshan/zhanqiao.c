// zhanqiao.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����ջ��");
	set("long", @LONG
ջ�������ϱ�Σ¥֮�䣬�����������̳ɣ�ÿ���������Žڲ�
����һ��ÿ������������ϣ�����ľ�壬����ʮ�ɣ�������Ԩ��ɽ��
��Х�����Ķ��ǡ�
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"south"   : __DIR__"xuankong2",
		"north"   : __DIR__"xuankong1",
	]));
	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3170);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
