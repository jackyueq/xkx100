// Room: /d/chengdu/shimiao2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "���۱���");
	set("long", @LONG
������ΰׯ�ϵĴ��۱�������������������Ĵ��գ��м乩��
����������Ľ��񣬵����������ƣ�����������Ů���������ͷ������
��һ�����ţ��������ݡ���������Ե�䣬��Ǯ�Ʋ�ʩ�á�
LONG	);
	set("exits", ([
		"south" : __DIR__"shimiao",
	]));
	set("objects", ([
		__DIR__"npc/yuanseng" : 1,
		__DIR__"obj/box1" : 1,
	]));
	set("coor/x", -8030);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

