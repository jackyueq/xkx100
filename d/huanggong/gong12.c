// Room: /d/huanggong/gong12.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������Ժ. ������һЩ��������, ����Ǻ�����Ů��ס��
�ط�. �����������������ܵ���ν��һ�빬�����ƺ���.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west"  : __DIR__"tinglang6",
		"north" : __DIR__"gong10",
	]));
	set("no_clean_up", 0);

	set("coor/x", -170);
	set("coor/y", 5300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}