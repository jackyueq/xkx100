// Room: /d/chengdu/shimiao.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�Ѿ���");
	set("long", @LONG
�Ѿ������д�������һ���֡�֮�ƣ�ʼ����������ꡣֻ�����ڵ�
�������ͥԺ�����ľ���졣��������ҷ���������������е���
��������ʿ���������޺��ȣ�������ü��Ŀ��
LONG	);
	set("exits", ([
		"south" : __DIR__"dongjie2",
		"north" : __DIR__"shimiao2",
	]));
	set("objects", ([
		__DIR__"npc/zhike" : 1,
		__DIR__"npc/xiaoheshang1" : 1,
	]));
	set("coor/x", -8030);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

