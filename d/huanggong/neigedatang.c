// Room: /d/huanggong/neigedatang.c

inherit ROOM;

void create()
{
	set("short", "�ڸ����");
	set("long", @LONG
�ڸ��������伮��, ��Ҫ�ռ�����; ����, ʵ¼��ʥѵ����.
LONG
	);
	set("exits", ([
		"northeast"  : __DIR__"wenhua",
	]));
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}