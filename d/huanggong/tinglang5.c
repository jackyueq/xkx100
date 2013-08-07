// Room: /d/huanggong/tinglang5.c

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
	set("exits", ([ /* sizeof() == 3 */
		"east"  : __DIR__"gong10",
		"west"  : __DIR__"gong9",
		"south" : __DIR__"tinglang6",
		"north" : __DIR__"tinglang4",
	]));
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}