// Room: /d/huanggong/rijing.c

inherit ROOM;

void create()
{
	set("short", "�վ���");
	set("long", @LONG
�վ��ű��������鷿, �ϱ��Ǽ��״�, �����ǻʵ۾����������ε�
�ط�.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"qianqingmen",
		"east" : __DIR__"yuqinggong",
	]));
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 5180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}