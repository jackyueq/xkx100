// Room: /d/songshan/shandao3.c
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
		"northup"   : __DIR__"songyuesi",
		"southeast" : __DIR__"shuyuan",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/zhao": 1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -20);
	set("coor/y", 780);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
