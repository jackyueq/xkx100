// Room: /d/5lt/jiulou1.c

inherit ROOM;

void create()
{
	set("short", "�û���¥");
	set("long", @LONG
������Ǵ�����������û���¥���������Ĵ�������������С��
����ͷ�󺹵��к������мα�����ʱ�������󻶸�Ц��......
LONG );
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"sroad1",
		"up"   : __DIR__"jiulou2",
	]));
	set("coor/x", -160);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

