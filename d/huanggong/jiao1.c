// Room: /d/huanggong/chengjiao.c

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
		"north" : __DIR__"dao2",
		"west"  : __DIR__"dao1",
		"up"    : __DIR__"lou1",
	]));
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/yulin2" : 2
	]));

	set("coor/x", -180);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}