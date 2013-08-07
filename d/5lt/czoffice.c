// Room: /d/5lt/czoffice.c

#include <room.h>
inherit  ROOM;

void  create  ()
{
	set  ("short",  "�峤�칫��");
	set  ("long",  @LONG
������Ǵ峤�칫�ҡ�����ķ��䣬ȴ���õþ����������������
����������˶�������ɫ�������㡣�ϱ���һ����(door)��
LONG);
	set("item_desc", ([
		"door" : "����һ�Ⱦ��ɵ�ľ�š�\n",
	]));
	set("exits",  ([  //sizeof()  ==  2
		"south"  :  __DIR__"huikeshi",
		"east"   :  __DIR__"chuandashi",
	]));
	set("objects", ([
		__DIR__"npc/fandog" : 1,
	]));

	create_door("south", "ľ��", "north", DOOR_CLOSED);
	set("no_fight", 1);
	set("coor/x", -170);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}
