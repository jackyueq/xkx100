// Room: /d/huanggong/tinglang3.c

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
		"west"  : __DIR__"gong5",
		"east"  : __DIR__"gong6",
		"north" : __DIR__"tinglang2",
	]));
	set("objects", ([ /* sizeof() == 3 */
		__DIR__"npc/pingwei" :1,
	]));

	set("coor/x", -220);
	set("coor/y", 5300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}