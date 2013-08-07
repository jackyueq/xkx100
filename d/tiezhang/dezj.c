// Room: /d/tiezhang/dezj.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
	set("short", HIG"�ڶ�ָ��"NOR);
	set("long", @LONG
�����ѵ�����ָ��İ�ɽ���ˣ���������ɽ���е�����ָһ����ÿ
��ɽ���ַ����أ�������ָ��ָ��һ�㣬�����������λ�ڵڶ�ָ�ڵ�
λ�á�������嶥�ѽ���͸���������������ѿ��Կ���ɽ·�ľ�ͷ�ˡ�
��ǰ����ʮ���ɴ��������������һ����Ѩ(dong)������������ʯ����
���ü���������
LONG	);
	set("exits", ([ /* sizeof() == 3 */
		"south"   : __DIR__"sslin5",
		"enter"   : __DIR__"dong1",
		"northup" : __DIR__"shanlu8",
	]));
	set("objects", ([
		__DIR__"npc/mayi" : 2,
	]));
	set("item_desc", ([ 
		"dong" : "һ���������ɽ�����ڰ���ż���м����׹������������ˣ�����\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", -1800);
	set("coor/z", 70);
	setup();
}

int valid_leave(object me, string dir)
{
	if(dir == "enter" && objectp(present("mayi zhanglao", environment(me))))
		return notify_fail("���³��Ϻȵ����������ư���أ��κ��˲������ڣ�����������������\n");

	return ::valid_leave(me, dir);
}
