// Room: /d/huanggong/gong4.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������Ժ. ������һЩ��������, ����Ǻ�����Ů��ס��
�ط�. �����������������ܵ���ν��һ�빬�����ƺ���. ���ڸ���һ
�� "�������" �ĵ���.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"gong2",
		"south" : __DIR__"gong6",
		"east"  : __DIR__"kunninggong",
		"west"  : __DIR__"tinglang2",
	]));
	set("no_clean_up", 0);

	set("coor/x", -210);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}