// Room: /lingzhou/yipindating.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "һƷ�ô���");
	set("long", @LONG
����������һƷ�õĴ��������������Ե��е����ޡ���ʮ���ϱ�
�������ſ����嶥�ķ��ܣ��������պ���ɭɭɷ�ˡ���������һ���ľ
�Ҷ�(bian)�������������ף�������������ľ������Ƥ�����ϣ�����
�����ŵģ����������󽫾������ܹܡ���Χ���ż���һƷ����ʿ���Ʒ�
������
LONG );
	set("item_desc", ([
		"bian"  : "һƷ��\n",
	]));
	set("exits", ([
		"south" : __DIR__"yipindayuan",
		"west"  : __DIR__"mishi",
	]));
	set("objects", ([
		"/quest/helian" :1,
		__DIR__"npc/yipinwushi" :4,
	]));
	set("no_fight",1);
	set("coor/x", -17970);
	set("coor/y", 32100);
	set("coor/z", 0);
	create_door("west","ľ��","east",DOOR_CLOSED);
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir =="west" )
	{
		if (present("wu shi", environment(me)))
                return notify_fail("һƷ����ʿһ�Բ����ص�����ǰ�档\n"); 
		return 1;
	}
	return ::valid_leave(me, dir);
}
