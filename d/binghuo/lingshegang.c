// Room: /binghuo/lingshegang.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ߵ�����");
	set("long", @LONG
���Ǹ���ľ�д�Ĵ󵺣��������ͦ�Σ������źü�����ɽ����
����ɽʯֱ���뺣������ǳ̲��������ֻ�������͡���ʱ����������
һ�Ҵ�(chuan)��������ֵ�����Φ�Ͼ�Ȼû�з�����
LONG );
	set("outdoors", "lingshe");
	set("no_clean_up", 0);
	set("item_desc", ([
		"chuan" : "һ����Φ�׷��������ϴ��Ϳ��Գ�����\n",
	]));
	set("exits", ([
		"westup"  : __DIR__"lingsheroad4",
		"enter"   : __DIR__"northboat1",
	]));
	setup();
	replace_program(ROOM);
}

