// Room: /d/songshan/songyueta.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ԭ�Ǳ�κ�빬��Т������Ϊ��Ժ�����巽�н�������Χ����
ɮ�����ơ�Ժ�ڷ綯����ҡ���ң�����һ���徲��
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao3",
		"northwest" : __DIR__"shandao4",
		"west"      : __DIR__"songyueta",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 790);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
