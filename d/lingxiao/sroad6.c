// Room: /d/lingxiao/sroad6.c
// Last Modified by Winder on Jul. 15 2001

#include <room.h>
inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@LONG 
�ߵ��������ů��һЩ�ˣ������ڹΣ�������ֻ������������ˮ
����һ���ײ����ҷ��д��£�����������������һˬ������������ڣ�
������������Ȼ�Ǹ���Ȫ���ұ����������м���ľ�ݣ�����������Ѳɽ
����ʱס��֮�ء�
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"    : __DIR__"water", 
		"east"    : __DIR__"muwu",
		"south"   : __DIR__"sroad5",
		"northup" : __DIR__"fentianya", 
	]));
	create_door("east", "ľ��", "west", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8950);
	set("coor/z", 110);
	setup();
	replace_program(ROOM); 
}

