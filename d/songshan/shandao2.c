// Room: /d/songshan/shandao2.c
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
		"northup"   : __DIR__"shuyuan",
		"southdown" : __DIR__"qimushi",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/sima": 1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -10);
	set("coor/y", 760);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
