// Room: /d/huanggong/gong11.c

inherit ROOM;

void create()
{
	set("short", "���ʹ�");
	set("long", @LONG
�����������Ժ. ������һЩ��������, ����Ǻ�����Ů��ס��
�ط�. �����������������ܵ���ν��һ�빬�����ƺ���.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"tinglang6",
		"north" : __DIR__"gong9",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}