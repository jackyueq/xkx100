// Room: /d/huanggong/jiao4.c

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
		"up"    : __DIR__"lou4",
		"north" : __DIR__"dao9",
		"east"  : __DIR__"dao10",
	]));
	set("no_clean_up", 0);

	set("objects", ([
		__DIR__"npc/yulin2" : 2,
	]));

	set("coor/x", -230);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}