// Room: /lingzhou/jiangjungate.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�󽫾���");
	set("long", @LONG
�����������󽫾����������ĸ��ڣ��ڶ���ֵ����У����������
�š�һɫ���ܴ��ݣ�����Уξ����ȥ�뺷���£��˿����������ֵĿ���
�䵶������ǰ��
LONG );
	set("exits", ([
		"north" : __DIR__"dongdajie",
		"south" : __DIR__"jjdayuan",
	]));
	set("objects", ([
		__DIR__"npc/xiaowei" : 2,
	]));
	set("coor/x", -17950);
	set("coor/y", 32060);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" && objectp(present("xiao wei", environment(me))))
		return notify_fail("Уξ��ס�����ȥ·���󽫾����ڸ��ϣ�\n");

	return ::valid_leave(me, dir);
}
