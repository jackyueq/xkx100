#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������������п׷����������ʵ۶������������˼����
�����Լ��Ľ�ɽ��𢣬�����ʵ���ȻҲ�����⡣���ۺ��˵��ˣ����Ϲ�
�Ͼ���������ݡ�
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("objects", ([
		"/d/city/obj/box" : 1,
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"xisi",
	]));
	set("coor/x", -210);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
