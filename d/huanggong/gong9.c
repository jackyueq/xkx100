// Room: /d/huanggong/gong9.c

inherit ROOM;

void create()
{
	set("short", "��Ǭ��");
	set("long", @LONG
�����������Ժ. ������һЩ��������, ����Ǻ�����Ů��ס��
�ط�. �����������������ܵ���ν��һ�빬�����ƺ���. ���������
��, ����עĿ�������ϵ�"��������"�Ҷ�.
LONG
	);
	set("objects", ([
		__DIR__"npc/gongnv" : 1,
	]));
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"kunninggong",
		"east"  : __DIR__"tinglang5",
		"north" : __DIR__"gong7",
		"south" : __DIR__"gong11",
	]));

	set("coor/x", -190);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}