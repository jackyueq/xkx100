// Room: /d/huanggong/huangjimen.c

inherit ROOM;

void create()
{
	set("short", "�ʼ���");
	set("long", @LONG
�ʼ���ͥԺ�Ĵ���. �ɴ�����, �ǻʵ�����̫�ϻ���������ĵ�
��, �׳� "�ⶫ·" . ��ǰ��������������ľ�������.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([
		"north"     : __DIR__"ningshoumen",
		"south"     : __DIR__"jianting",
		"west"      : __DIR__"yuqinggong",
	]));
	set("no_clean_up", 0);
	set("coor/x", -180);
	set("coor/y", 5180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}