// Room: /d/nanshaolin/talin1
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
��������������ɮ�µ�Ĺ�أ��ϰ���Ĺ��ʽ�����࣬���͸��졣��
�������У�ֻ�����ۻ����ң���֪�����ĸ������ߣ����ƺ���·�ˡ�
LONG );
	set("exits", ([
		"northeast" : __DIR__"talin2",
		"southeast" : __DIR__"talin"+(random(10)+1),
		"northwest" : __DIR__"talin"+(random(10)+1),
		"southwest" : __DIR__"talin"+(random(10)+1),
		"south"     : __DIR__"talin"+(random(10)+1), 
                "west"      : __DIR__"talin"+(random(10)+1),
                "north"     : __DIR__"talin"+(random(10)+1),
                "east" : __DIR__"slyuan",
	]));
	create_door("east", "ľ��", "west", DOOR_CLOSED);
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1780);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

