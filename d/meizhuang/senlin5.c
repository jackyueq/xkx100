// /d/meizhuang/senlin5.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "��ľ԰");
	set("long", @LONG
������÷ׯ�İ�ľ԰����һ�ߵ���������ߵ���һ�������޾���
Сɭ��һ��������������������������������кܶ�в��������ֵ�
������ľ�����������У�ֻ�����Ƭ���־��������һ�飬������ȥ��
�á�
LONG
	);
	set("exits", ([ /* sizeof() == 8 */
		"west"      : __DIR__"senlin2",
		"east"      : __DIR__"senlin2",
		"north"     : __DIR__"senlin3",
		"south"     : __DIR__"senlin5",
		"southeast" : __DIR__"senlin4",
		"northeast" : __DIR__"senlin2",
		"northwest" : __DIR__"senlin4",
		"southwest" : __DIR__"senlin6",
	]));
	set("outdoors", "meizhuang");
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1420);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
