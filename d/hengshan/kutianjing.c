// Room: /d/hengshan/kutianjing.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����������½ǣ��ж�����಻�����ߣ���ˮ��һ��һ�𣬳�Ϊ��
���𾮡�������ˮζ��䣸��𣬵��ҵ��ӷ�Ϊʥˮ�����˵��ˣ�ÿ��
�ڿ��������ˮȷ����������֮�档
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"beiyuemiao",
	]));
	set("resource/water", 1);
	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", 40);
	set("coor/y", 3170);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

