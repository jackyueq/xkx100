// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����������������������������Ϸ������������顰���Һ�
ɽ���ĺ��ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ�����
���������Ϲ��Ͼ���������ݡ��Ա��ƺ���һ�����š�
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");

	set("valid_startroom","1");
	set("objects", ([
		__DIR__"obj/box" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"shilijie3",
		"up"   : __DIR__"wumiao2",
		"northwest": "/d/wizard/guest_room",
	]));
        create_door("northwest", "����", "southeast", DOOR_CLOSED);
	set("coor/x", 0);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        "/clone/board/wiz2_b"->foo();
}

void init()
{
	object me;
	me=this_player();
	if (!wizardp(me)) me->set("startroom",base_name(environment(me)));
	if (!wizardp(me)) me->save();
	return;
}