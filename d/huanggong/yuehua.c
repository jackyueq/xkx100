// Room: /d/huanggong/yuehua.c

inherit ROOM;

void create()
{
	set("short", "�»���");
	set("long", @LONG
�»��ű�����������, �ϱ������·�, �����ǻʵ۾����������ε�
�ط�.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"qianqingmen",
		"west" : __DIR__"yangxin",
	]));
	set("no_clean_up", 0);

	set("coor/x", -210);
	set("coor/y", 5280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}