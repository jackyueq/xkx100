// Room: /d/yueyang/shijie1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
�������ڶ������ʯ�ף��������ں�ɽ�ϵ�����ͤ��ʯ�����߲���
���࣬�������ˣ����Ǹ��������ڡ���ɽ�£���ͥ��ˮ��ӵ��ɽ�����
һƬ��ʮ�����ˡ�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"eastup"   : __DIR__"langyinting",
		"westdown" : __DIR__"longkou",
	]));
	set("coor/x", -1710);
	set("coor/y", 2290);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
