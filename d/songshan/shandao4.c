// Room: /d/songshan/shandao4.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
����������ɽ�������ɴ�أ�ɽ�����ʱ��Ʈ����Զ��ɽ��Ȯ��
���䣬�����ɷ�֮�С�
LONG );
	set("exits", ([
		"northup"   : __DIR__"fawangsi",
		"southeast" : __DIR__"songyuesi",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/zhang": 1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -30);
	set("coor/y", 800);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
