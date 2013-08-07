// Room: /d/huanggong/jianting.c

inherit ROOM;

void create()
{
	set("short", "�Ͻ���ͤ");
	set("long", @LONG
��һ��Ƭ�յ�����һ����ͤ, �ֳ��Ͻ���ͤ, ���ϳ������������
����һ�����, ��������.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 6 */
		"north" : __DIR__"huangjimen",
		"south" : __DIR__"yushanfang",
		"west"  : __DIR__"jingyunmen",
		"east"  : __DIR__"dao3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -180);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}