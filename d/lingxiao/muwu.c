// Room: /d/lingxiao/muwu.c
// Last Modified by Winder on Jul. 15 2001

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "ľ��");
	set("long", @LONG
���������ǵ����ڳ���Ѳ�߻�ɽ��������ÿ�춼��ѩɽ����������
�Ա��������ǰ�ȫ�徻��������ƾ�������������е���ͷ��һ����С֮
��Ҳ�������˵��ҡ�
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"sroad6",
	]));
	create_door("west", "ľ��", "east", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", -30990);
	set("coor/y", -8950);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
} 

