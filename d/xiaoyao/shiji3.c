// shiji3.c
// Modified by Winder June.25 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ�����ϱ�������չ��ʯ������������ȱ�������������е���
ɭɭ�ĸо��������Ǹ����ε�ͭ�ţ������Ǹ�ʯ�ҡ�
LONG );
	set("exits", ([
		"south" : __DIR__"shishi2",
		"north" : __DIR__"tongmen",
	]));
	create_door("south", "ʯ��", "north", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", -21030);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}