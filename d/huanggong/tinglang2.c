// Room: /d/huanggong/tinglang2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ܵ���������. ������ϲ�˵Ļ���, վ�����, ��Լ���õ���
��������Ů����Ц������, �����������������, �Եþ�������, ����
����Ĺ��ͦ�ϵ�.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"tinglang1",
		"south" : __DIR__"tinglang3",
		"west" : __DIR__"gong3",
		"east" : __DIR__"gong4",
	]));
	set("no_clean_up", 0);

	set("coor/x", -220);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}