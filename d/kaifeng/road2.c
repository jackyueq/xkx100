// /kaifeng/road2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ϱ��Ľֵ��ǻ��ϳ�Ѳʱ��Ҫ��������������������ӯ�ţ�
���ߵ��̲��ϡ��ֵ������������ĵ���ӡ�
LONG);
	set("no_clean_up", 0);
	set("outdoors", "kaifeng");
	set("exits", ([
		"north" : __DIR__"road3",
		"south" : __DIR__"zhuque",
		"west"  : __DIR__"gongyuan3",
		"east"  : __DIR__"daoxiang1",
	]));

	setup();
	replace_program(ROOM);
}
