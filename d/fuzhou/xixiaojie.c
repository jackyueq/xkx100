// Room: /d/fuzhou/ximendajie.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "��С��");
	set("long", @LONG
��ʯ��·��ֱ����չ��ȥ��ֱͨ���š��ֱ���ȥ����һƬ������ˮ
ɫ������ȴ��һƬ���֣�������ʣ���Զ������
LONG );
	set("exits", ([
		"west"  : __DIR__"ximen",
		"east"  : __DIR__"xidajie",
		"north" : __DIR__"xihu",
		"south" : __DIR__"xichansi",
	]));
	set("objects", ([
		__DIR__"npc/cui": 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1820);
	set("coor/y", -6300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
