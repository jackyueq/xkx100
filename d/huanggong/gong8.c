// Room: /d/huanggong/gong8.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������Ժ. ������һЩ��������, ����Ǻ�����Ů��ס��
�ط�. �����������������ܵ���ν��һ�빬�����ƺ���. �������һ
���ʹ��г������Ҷ�: "��������".
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"tinglang4",
		"south" : __DIR__"gong10",
	]));
	set("no_clean_up", 0);

	set("coor/x", -170);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}