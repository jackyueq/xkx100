// Room: /d/chengdu/chufang.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�ų�������̨�Ϸ���������������ÿ�ڹ���ǰ����һλ��ʦ����
�������ں���䤱��س��Ųˡ�
LONG	);
	set("exits", ([
		"west" : __DIR__"chenmapo",		
	]));
	set("objects", ([
		__DIR__"npc/dashifu" : 3,
	]));
	set("coor/x", -8030);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

