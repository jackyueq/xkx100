// /yubifeng/xiaolu1.c
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
		"west"  : __DIR__"songlin4",
		"east"  : __FILE__,
		"south" : __DIR__"xiaolu2",
		"north" : __FILE__,
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6110);
	set("coor/y", 5150);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
