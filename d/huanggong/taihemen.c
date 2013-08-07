// Room: /d/huanggong/taihemen.c

inherit ROOM;

void create()
{
	set("short", "̫����");
	set("long", @LONG
����������ǰ��. ��ǰ����һ��ͭ��ʨ��, ������ֻ��ʨǰ��̤
����, ����Ȩ����ͳһ���. ������ֻ��ʨ, ǰ֫��ŪһС��ʨ, ����
���ò�ʢ.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"wumen",
		"north" : __DIR__"guangchang",
	]));
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}