// Room: /d/yanziwu/qiuyu.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "����ի");
	set("long", @LONG
����ի�߾�ɽ��֮�ϣ�����ʮ���ɾ���̫����ˮ���ˡ�����ɽׯ��
������ʱ�⣬����ˮ��������˿�����µ��գ����������ߣ������ޱ�
����Ӧʱ���������˼��ɾ���
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown"   : __DIR__"path19",
	]));
	set("coor/x", 1190);
	set("coor/y", -1260);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}