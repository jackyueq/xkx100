// Room: /d/huanggong/jiao3.c

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
		"south" : __DIR__"dao7",
		"up"    : __DIR__"lou3",
		"east"  : __DIR__"dao6",
	]));
	set("no_clean_up", 0);

	set("objects", ([
		__DIR__"npc/yulin2"  : 2,
	]));

	set("coor/x", -230);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}