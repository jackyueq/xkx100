// Room: /d/chengdu/zhubaopu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�ܼ��鱦��");
	set("long", @LONG
����һ��רӪ�������鱦������ε꣬�ϰ�Ͱ����ף������ܵ���
��������Ҽ������͸���������ˣ��ǾͲ�Ҫ����ԥ�ˣ��Ͻ���Ǯׯȡ
Ǯ�ɡ�
LONG	);

	set("exits", ([
		"west" : __DIR__"beijie",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8040);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

