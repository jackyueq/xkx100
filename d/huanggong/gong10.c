// Room: /d/huanggong/gong10.c

inherit ROOM;

void create()
{
	set("short", "���͹�");
	set("long", @LONG
�����������Ժ. ������һЩ��������, ����Ǻ�����Ů��ס��
�ط�. �����������������ܵ���ν��һ�빬�����ƺ���.
LONG
	);
	set("objects", ([
		__DIR__"npc/gongnv" : 1,
		__DIR__"npc/hui" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"tinglang5",
		"south" : __DIR__"gong12",
		"north" : __DIR__"gong8",
	]));

	set("coor/x", -170);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}