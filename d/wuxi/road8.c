// Room: /d/wuxi/road8.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "���С��");
	set("long", @LONG
·���ߵ������Ͱ�����࣬��಻֪����СҰ��������е�����
ȥ��͸����֦�������߶���һ���޼ʵ���Ұ������ôҲ�����뵽����
����������Խ�Ļ���÷���ˡ�
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"   : __DIR__"road7",
		"west"   : __DIR__"road9",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
	set("coor/x", 360);
	set("coor/y", -860);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}