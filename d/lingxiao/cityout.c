// Room: /d/lingxiao/cityout.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����������ǵĳ��⣬����������ǰ���Ǹ��ʵĳ�ǽ�����������
�ӳ����ߣ���ҪԽǽ���룬�ǲ�̫���ܵġ���������Ұ�Ǻܶ࣬���Բ�
��ʲô��ȫ�ĵط������ǸϿ���ǰɡ�
LONG
	);
	set("exits", ([
		"west" : __DIR__"shanya",
	]));
	set("objects", ([
		__DIR__"npc/wolf" : 2,
	]));
	set("outdoors", "lingxiao");
	set("coor/x", -30990);
	set("coor/y", -8940);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

