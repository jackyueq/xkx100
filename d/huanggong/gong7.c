// Room: /d/huanggong/gong7.c

inherit ROOM;

void create()
{
	set("short", "�Ӵ⹬");
	set("long", @LONG
�����������Ժ. ������һЩ��������, ����Ǻ�����Ů��ס��
�ط�. �����������������ܵ���ν��һ�빬�����ƺ���.
LONG
	);
	set("objects", ([
		__DIR__"npc/gongnv" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east"  : __DIR__"tinglang4",
		"south" : __DIR__"gong9",
	]));

	set("coor/x", -190);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}