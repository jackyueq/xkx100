// Room: /binghuo/shanlu2.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ʯɽС·");
	set("long", @LONG
���ڻ�ɽʯ�Ĵ��ƬҶ������ɽ·�ϡ����¾���ï�ܵĴ������ˡ�
�����ɽ�Ʒǳ�����������������ȥ�ˡ�
LONG );
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"shanlu1",
	]));
	setup();
	replace_program(ROOM);
}

