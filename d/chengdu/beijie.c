// Room: /d/chengdu/beijie.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��������˫�˺ϱ�����ͩʮ��һ�꣬�������룬��ʯ�̾͵�·���
ɨ�øɸɾ����������Ǹ��鱦�̣����������������µ������ھ֡�
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"zhubaopu",
		"west"  : __DIR__"biaoju",
		"south" : __DIR__"beijie1",
		"north" : __DIR__"northgate",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke" : 1,
	]));
	set("coor/x", -8050);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

