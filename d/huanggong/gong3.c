// Room: /d/huanggong/gong3.c

inherit ROOM;

void create()
{
	set("short", "��Ԫ��");
	set("long", @LONG
�����������Ժ. ������һЩ��������, ����Ǻ�����Ů��ס��
�ط�. �����������������ܵ���ν��һ�빬�����ƺ���.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"tinglang2",
		"north" : __DIR__"gong1",
		"south" : __DIR__"gong5",
	]));
	set("no_clean_up", 0);

	set("coor/x", -230);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}