// Room: /d/huanggong/nanxundian.c

inherit ROOM;

void create()
{
	set("short", "��Ѭ��");
	set("long", @LONG
��Ѭ�����ľ��, �微���컨, �ʻ���������. �����µ�, ��Ҫ��
�������ĸ�������, �����в����, ���ڴ�д�𱦲�. �������
�����ۺ���ʥ���͵�ͼ��.
LONG
	);
	set("exits", ([
		"north"     : __DIR__"wuying",
	]));
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}