// Room: /d/yueyang/xiaolu6.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ھ�ɽ��´�������������ϡ���ɽ������ʮ������ɣ�����
���㣬���̲���������������ɫȫ�޴�ɫ�����ˮ����ϴ����һ����
�쾵���ġ�������Ұ��έҶ���롢������죬��ɽ�Ĳ��㡣���ɵ�����
������������ɶ�����
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"enter"     : __DIR__"xiangfeici1",
		"northwest" : __DIR__"xiaolu7",
		"southwest" : __DIR__"erfeimu",
	]));
	set("coor/x", -1660);
	set("coor/y", 2310);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
