// Room: /d/songshan/taishique.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "̫����");
	set("long", @LONG
��ɽ�ųƷ��⣬�ֳƳ�ɽ��Ϊ�����е���������̫�����Ҷ�ɽ����
���ɡ������ʱ�ơ��Ըߡ���ȡ��ʫ��������ά�ߣ��������족������
��֮Ϊ����С���졣�׸����࣬����̡�����̫�����ǡ����֣�׭�Ĺ�
�ӣ��Ծ���������������ȥ����ɽ�����µ�·����һ�������������
�ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"tianzhongge",
		"south" : "/d/kaifeng/shanlu2",
		"east"  : "/d/nanyang/ruzhou",
		"west"  : "/d/shaolin/shijie1",
	]));
	set("outdoors", "songshan");
	set("objects", ([
		__DIR__"npc/dizi" : 1,
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", 700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
