// Room: /d/baituo/zhulin.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long", @LONG
�����������֣������߳�û���ϱ�����ݴԡ�������һ�����Ҷ���
LONG	);
	set("exits",([
		"northup" : __DIR__"cave",
		"south"   : __DIR__"cao2",
	]));
	set("objects",([
		__DIR__"npc/qingshe" : random(2),
		__DIR__"npc/snake" : random(3),
	]));
	set("coor/x", -50040);
	set("coor/y", 20060);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
