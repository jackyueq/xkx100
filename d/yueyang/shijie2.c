// Room: /d/yueyang/shijie2.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ����ʯ�ף�����ɽ�ϵ�����ͤ��ɽ�µĶ���Ĺ��ʯ�����߲�
�����࣬�������ˣ����Ǹ��������ڡ�Զ����ͥ����ˮ��ӵ��ɽ������
����ɽ����һƬ��⡣
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"westup"    : __DIR__"langyinting",
		"northeast" : __DIR__"erfeimu",
		"southwest" : __DIR__"xiaolu3",
	]));
	set("coor/x", -1680);
	set("coor/y", 2290);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
