// Room: /d/yueyang/jiuxiangting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����ͤλ�ھ�ɽ�������ɽ���������ഫ�����꺺�����˵��ɽ��
������̳����֮���ɣ�����ͯ��ͯŮȥȡ���ر�ֻ�ž��㣬�����Ƽ���
��ֻ�����ա��Ӵˣ���ɽ��������ˡ����㡱֮�������������۵Ķ��
�۾�ͤ��Ҳ�ԡ����㡱������Сͤ���ķ��Σ���ӳ�ڴ�������֮�С�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"north"    : __DIR__"jiuxiangshan",
		"south"    : __DIR__"shijie6",
		"eastdown" : __DIR__"shijie5",
		"westdown" : __DIR__"xiaolu9",
	]));
	set("coor/x", -1780);
	set("coor/y", 2280);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
