// /yubifeng/songlin3.c
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
		"east"  : __DIR__"songlin1",
		"west"  : __DIR__"songlin1",
		"north" : __DIR__"songlin2",
		"south" : __DIR__"songlin4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6110);
	set("coor/y", 5190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
