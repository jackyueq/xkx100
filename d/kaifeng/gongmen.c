// /kaifeng/gongmen.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "ʯ����");
	set("long", @LONG
��ʯͷ��������һ�����ţ���Խ���ɣ������ο����ơ�������˩��
��ʯ��������ǰ��һ��ĵط����п����ʯ������������޴��ʯͷ��
һ���񵽵��£��ںͿڵĵط����и���׿��Բ���ˡ�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"southup" : __DIR__"8bao",
		"northdown" : __DIR__"road1",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
