// Room: /d/chengdu/niangjiuwu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����ʽ�ķ����м䡣�������������һ���ܴ�ܴ��ľͰ��
Լ�ж��˶�ߡ���ľͰ�����棬վ�ż�������������Ĵ󺺣���������
����ڷ����ĳ�ľͰ�����š���ǰ��վ��һ�����ϵ�����ںͼ���С
����ü����ȥ��˵Ц�š�
LONG	);
	set("exits", ([
		"northwest" : __DIR__"xiaojie2",
	]));
	set("objects", ([
		__DIR__"npc/wangerniang" : 1,
		__DIR__"npc/xiaohuozi" : 3,
	]));
	set("coor/x", -8000);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

