// Room: /d/huanggong/duangning.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǻ���������۴��ĺͽ��ߵĶ�����.
LONG
	);
	set("exits", ([
		"west" : __DIR__"qianqinggong",
	]));
	set("objects", ([
		__DIR__"npc/wenyoudao" :1,
	]));
	set("coor/x", -190);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}