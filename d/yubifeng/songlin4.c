// /yubifeng/songlin4.c
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
		"west"  : __DIR__"songlin5",
		"east"  : __DIR__"songlin3",
		"north" : __DIR__"songlin3",
		"south" : __DIR__"songlin2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6110);
	set("coor/y", 5180);
	set("coor/z", 0);
	setup();
}

void init()
{
	object me = this_player();
	if (random(5) == 1)
	set("exits", ([
		"west"  : __DIR__"songlin5",
		"east"  : __DIR__"xiaolu1",
		"north" : __DIR__"songlin3",
		"south" : __DIR__"songlin2",
	]));
}

