// pine_road1.c ����С��
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����ɽ�������е�С·�����߳�������ĺ�������ֻ�ܿ���һ����
�ա�·���е�ʿ�ڷ�����(chop)��������ͨ����������ϱ߿ɻش����
LONG
	);
	
	set("objects", ([
		CLASS_D("wudang") + "/famu" : 1,
		__DIR__"obj/pine" : 2
	]));
	set("exits", ([
		"north" : __DIR__"pine_forest0",
		"south" : __DIR__"pine_road",
	]));
	set("outdoors", "wudang");
	
	setup();
	replace_program(ROOM);
}

