// Room: /d/chengdu/eastroad2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��������ӣ��ſڹ���һ������ɵĺ������ͻ������������ż���
����ֽ���м����������ջ�������
LONG	);
	set("exits", ([
		"west" : __DIR__"nanjie1",
	]));
	set("objects", ([
		__DIR__"npc/poorman" : 1,
	]));
	set("coor/x", -8040);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

