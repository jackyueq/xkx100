// xiaodao2.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һ���������ּ�С�����Ӷ���һֱͨ�����ߣ�һ����ȥ������
��·�ľ�ͷ�����԰ٻ����ޡ����������������ϱߺ�������ζɢ��������
�����Ǹ���������
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"shantang",
		"east" : __DIR__"xiaodao1",
		"west" : __DIR__"xiuxis",
		"north" : __DIR__"bingqif",
	]));
	set("no_clean_up", 0);
	set("outdoors", "xiaoyao");
	set("coor/x", 60);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}