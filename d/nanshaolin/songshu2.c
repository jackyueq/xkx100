// Room: /d/nanshaolin/songshu2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֡��߸ߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����
ɡ��������գ��������ڵ�˿��Ҳ�ޡ�һ���ྻ����ʯС���������С�
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"east"  : __DIR__ "lunhuisuo",
		"west"  : __DIR__ "stoneroad1",
		"north" : __DIR__ "songshu1",
		"south" : __DIR__ "songshu3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



