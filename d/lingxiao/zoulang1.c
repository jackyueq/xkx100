// Room: /d/lingxiao/zoulang1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","����");
	set("long",@LONG 
����һ�����������ȡ����¶����������ӵľ����������ǹ����ӵ�
���ң���˵��Ŀǰ���ڹ�����ͽ���ϱ���������ķ��䡣������һ����
����С�䣬��������˯����Ϣ��
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"sleep",
		"east"  : __DIR__"zhongting",
		"north" : __DIR__"roomgeng",
		"south" : __DIR__"roomwang", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8870);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

