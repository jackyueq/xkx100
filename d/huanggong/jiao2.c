// Room: /d/huanggong/jiao2.c

inherit ROOM;

void create()
{
	set("short", "�ǽ�");
	set("long", @LONG
�������ڳǵ�һ��, ͷ�ϵ����ֻ�ܼ�������һ��. ��������Ư��
�Ľ�¥.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 3 */
		"west"  : __DIR__"dao5",
		"up"    : __DIR__"lou2",
		"south" : __DIR__"dao4",
	]));
	set("no_clean_up", 0);

	set("objects", ([
		__DIR__"npc/yulin2" : 2,
	]));

	set("coor/x", -180);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}