// Room: /d/yueyang/xiaolu3.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
�����ھ�ɽ��´�ĺ�����ʯС·�ϡ���ɽ������ʮ������ɣ����
�����㣬���̲���������������ɫȫ�޴�ɫ�����ˮ����ϴ����һ��
���쾵���ġ�������Ұ��έҶ���롢������죬��ɽ�Ĳ��㡣���ɵ���
��������������ɶ�����
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"shijie2",
		"southwest" : __DIR__"fengshanyin",
	]));
	set("coor/x", -1690);
	set("coor/y", 2280);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
