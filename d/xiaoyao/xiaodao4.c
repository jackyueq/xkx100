// xiaodao4.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һ���������ּ�С�����Ӷ���һֱͨ�����ߣ�һ����ȥ������
��·�ľ�ͷ�����԰ٻ����ޡ���������������
LONG );
	set("exits", ([
		"east" : __DIR__"shulin1",
		"west" : __DIR__"qingcaop",
		"north" : __DIR__"liangong",
		"south" : __DIR__"mubanlu",
	]));
 	set("objects", ([
		CLASS_D("xiaoyao")+"/wulingjun": 1,
		__DIR__"npc/mengmianr": 2,
	]));
	set("outdoors", "xiaoyao");
	set("coor/x", 90);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}