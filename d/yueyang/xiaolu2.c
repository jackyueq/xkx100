// Room: /d/yueyang/xiaolu2.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
�����ھ�ɽ��´�ĺ���С·�ϡ���ɽ������ʮ������ɣ�������
�㣬���̲���������������ɫȫ�޴�ɫ�����ˮ����ϴ����һ������
�����ġ�������Ұ��έҶ���롢������죬��ɽ�Ĳ��㡣���ɵ�������
�����������ɶ�����
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"longkou",
		"west"      : __DIR__"shejiaotai",
	]));
	set("coor/x", -1730);
	set("coor/y", 2280);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
