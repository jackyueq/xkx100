// /kaifeng/eroad1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������ǿ��⸮�ڶ���������Ҫͨ������·�����˵��̸��ڲ��ϡ�
�������ƣ��۹�ģ�������ģ��ʽ���ģ��������׷��ѵģ������ޱȡ�
���߲�Զ����ɽ�¸ʻ�ݡ�
LONG);
	set("objects", ([
		__DIR__"npc/hanzi" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"eroad0",
		"north" : __DIR__"eroad2",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
