// Room: /d/songshan/westting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "��ͥ");
	set("long", @LONG
������һ��ССͥԺ��Ժ���ﳣ����ɽ���ӽ��������ͥԺ���ܰ�
ǽ�³��ŵ�С��ľ�ż��ð�����ǰ�ɫС��������ϸʯ�̾͵�С·��
��ľ�Ժͳ��ݼ䴩����
LONG );
	set("outdoors", "songshan");
	set("exits", ([
		"east"  : __DIR__"westpath1",
		"west"  : __DIR__"chufang",
		"north" : __DIR__"westpath2",
		"south" : __DIR__"cangku",
	]));
	set("objects", ([
		__DIR__"npc/dizi": random(2),
	]));
	set("coor/x", -40);
	set("coor/y", 900);
	set("coor/z", 90);
	setup();
	create_door("south" , "ľ��", "north" , DOOR_CLOSED);
	replace_program(ROOM);
}
