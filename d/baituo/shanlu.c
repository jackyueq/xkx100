// Room: /d/baituo/shanlu.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","ɽ·");
	set("long", @LONG
������ɽ�ϵ���·�����������ܵĴ��֣�ż�������ټ������ϱ�һ
�����ѵ�С·ͨ��ɽ�µĴ�ׯ��
LONG	);
	set("exits",([
		"northwest" : __DIR__"shanlu1",
		"southeast" : __DIR__"guangchang",
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("coor/x", -50020);
	set("coor/y", 20000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
