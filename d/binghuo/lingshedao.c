// Room: /binghuo/lingshedao.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ߵ���̲");
	set("long", @LONG
���Ǹ���ľ�д�Ĵ󵺣��������ͦ�Σ������źü�����ɽ����
����ɽʯֱ���뺣������ǳ̲��������ֻ�������͡�
LONG );
	set("outdoors", "lingshe");
	set("exits", ([
		"east"  : __DIR__"lingsheroad1",
	]));
	set("objects", ([
		__DIR__"npc/yinli" : 1,
	]));
	setup();
	replace_program(ROOM);
}

