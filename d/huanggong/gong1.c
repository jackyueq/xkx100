// Room: /d/huanggong/gong1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������Ժ. ������һЩ��������, ����Ǻ�����Ů��ס��
�ط�. �����������������ܵ���ν��һ�빬�����ƺ���. ���й���һ
����ľ����: "ï������".
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east"  : __DIR__"tinglang1",
		"south" : __DIR__"gong3",
	]));
	set("no_clean_up", 0);

	set("coor/x", -230);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}