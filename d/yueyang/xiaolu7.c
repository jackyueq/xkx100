// Room: /d/yueyang/xiaolu7.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��ʯɽ��");
	set("long", @LONG
�������ھ�ɽ��´ͨ�����������ʯɽ���ϡ���ɽ������ʮ������
�ɣ��������㣬���̲���������������ɫȫ�޴�ɫ�����ˮ����ϴ
����һ�����쾵���ġ�������Ұ��έҶ���롢������죬��ɽ�Ĳ��㡣
���ɵ�����������������ɶ�����
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"qiuyueqiao",
		"southeast" : __DIR__"xiaolu6",
	]));
	set("coor/x", -1670);
	set("coor/y", 2320);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
