// Room: /d/huijiang/goldroom.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������");
	set("long",@LONG
����һ��С���ӣ����ϸɸɾ������˳���Ⱦ���ϱ߿�ǽ�ǵĵط���
�ż������ӣ���������������˴�����۵ĺ����յ�������ͬ����һ
�㡣
LONG );
	set("exits", ([
		"east" : __DIR__"zongduo",
	]));
	set("objects", ([
		CLASS_D("honghua")+"/xu-tianhong" : 1,
		__DIR__"obj/box" : 1,
	]));	
	set("coor/x", -50080);
	set("coor/y", 9150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
