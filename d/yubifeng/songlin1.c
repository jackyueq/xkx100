// /yubifeng/songlin1.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬï�ܵ����֣����ҵ���������б��ɽ���ϡ�������������
�������������֦�½��ᣬ������ѹ�����ߺ�İ�ѩ����������ѩ�٣�
�������ߡ�
LONG );
	set("exits", ([
		"northwest" : "/d/guanwai/xuedi1",
		"west"      : __FILE__,
		"north"     : __FILE__,
		"south"     : __FILE__,
		"east"      : __DIR__"songlin2",
	]));
	set("objects", ([
		__DIR__"npc/walker": 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6100);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
