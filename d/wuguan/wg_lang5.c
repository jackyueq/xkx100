// wg_lang5.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ȣ�ͨ����������ң����ﾲ���ĵģ�û��ʲô������
����������������ɽ�����������գ�����������������ֻ����һ��
������
LONG);
	set("exits", ([
		"out"   : __DIR__"wg_dating",
		"east"  : __DIR__"wg_woshi",
		"south" : __DIR__"wg_shufang",
	]));
	set("objects", ([
		__DIR__"npc/wg_yahuan" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 31);
	set("coor/y", -40);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

