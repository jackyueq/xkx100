// Room: /d/heimuya/chitang.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
����һ��С������������������ԧ��������䣬�ر߻��м�ֻ�׺�
����ʳ��
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"north" : __DIR__"baihutang",
		"west"  : __DIR__"shenggu",
		"east"  :__DIR__"chufang2",
	]));
	set("objects",([
		"/d/dali/npc/xianhe" : 1 + random(3),
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 3990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}