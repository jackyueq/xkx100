// Room: /d/huanggong/gong6.c

inherit ROOM;

void create()
{
	set("short", "���ٹ�");
	set("long", @LONG
�����������Ժ. ������һЩ��������, ����Ǻ�����Ů��ס��
�ط�. �����������������ܵ���ν��һ�빬�����ƺ���.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"tinglang3",
		"north" : __DIR__"gong4",
	]));
	set("no_clean_up", 0);

	set("coor/x", -210);
	set("coor/y", 5300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}